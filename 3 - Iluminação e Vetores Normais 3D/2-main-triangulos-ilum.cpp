/// MS VS 
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
using namespace std;

GLfloat angleV, fAspect;
char title[] = "OpenGL-PUC PR: PROJEÇÃO PERSPECTIVA COM ILUMINAÇÃO";

GLfloat posicaoLuz[4] = { 0.0f, 150.0f, 500.0f, 1.0f };

GLfloat angle = 0.0f, angle1 = 0.0f;

// Inicializa parâmetros de rendering
void initGL(void)
{
	angleV = 45.0f;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);			  // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);				  // Set the type of depth-test
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

	GLfloat luzAmbiente[4] = { 0.2f,0.2f,0.2f,1.0f };
	GLfloat luzDifusa[4] = { 0.5f,0.5f,0.5f,1.0f };
	GLfloat luzEspecular[4] = { 0.5f,0.5f,0.5f,1.0f };

	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0f,1.0f,1.0f,1.0f };
	GLint especMaterial = 40.0f;
	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Define a refletância do material 
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
	// Modo de sombreamento - sólido, sem interpolação (FLAT)
	glShadeModel(GL_FLAT);
	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
}

// Função usada para especificar o volume de visualização
void setVisParam(void)
{
	glMatrixMode(GL_PROJECTION); 	// Especifica sistema de coordenadas de projeção
	glLoadIdentity(); 				// Inicializa sistema de coordenadas de projeção
	// Especifica a projeção perspectiva - cria o volume de visualização (frustum)
	gluPerspective(angleV, fAspect, 0.1f, 500.0f); // fovy, aspect ratio, zNear, zFar

	glMatrixMode(GL_MODELVIEW); // Especifica sistema de coordenadas do modelo
	glLoadIdentity(); 	        // Inicializa sistema de coordenadas do modelo
	// Especifica posição do observador e do alvo
	gluLookAt(0.0f, 30.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ
}

// Função callback chamada quando o tamanho da janela é alterado 
void reshape(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	setVisParam();
}
// Keyboard ... processamento das teclas especiais (setas)
void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		angle1--;
		break;
	case GLUT_KEY_RIGHT:
		angle1++;
		break;
	case GLUT_KEY_UP:
		angle--;
		break;
	case GLUT_KEY_DOWN:
		angle++;
		break;
	}
	glutPostRedisplay();
}

// Função callback chamada para fazer o desenho
void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glPushMatrix();

	glRotatef(angle, 1.0f, 0.0f, 0.0f); // rotação da cena em x
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);// rotação da cena em y

	glColor3f(1.0, 1.0, 0.5);
//	glutSolidTeapot(5.0f);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0); // White // Anti-Horário
		glVertex3f(0.0, 0.0, 5.0);
		glVertex3f(10.0, 0.0, 5.0);
		glVertex3f(5.0, 10.0, 5.0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0, 0.0, 0.0); // red  // Horário
		glVertex3f(0.0, 0.0, +10.0);
		glVertex3f(0.0, +10.0, +10.0);
		glVertex3f(+10.0, 0.0, +10.0);
		glColor3f(0.0, 1.0, 0.0); // green
		glVertex3f(0.0, -10.0, +10.0);
		glColor3f(0.0, 0.0, 1.0); // blue
		glVertex3f(-10.0, 0.0, +10.0);
		glColor3f(1.0, 1.0, 0.0); // yellow
		glVertex3f(0.0, +10.0, +10.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0, 0.0, 1.0); // magenta  // Horário
		glVertex3f(0.0, 0.0, -10.0);
		glVertex3f(0.0, +10.0, -10.0);
		glVertex3f(+10.0, 0.0, -10.0);
		glColor3f(0.0, 1.0, 1.0); // ciano
		glVertex3f(20.0, 10.0, -10.0);
		glColor3f(0.0, 1.0, 0.0); // green
		glVertex3f(20.0, 0.0, -10.0);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

// Programa Principal
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);     // Set the window's initial width & height
	glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(render);          // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);         // Register callback handler for window re-size event
	initGL();                         // Our own OpenGL initialization
	glutSpecialFunc(processSpecialKeys);  // Register callback handler for arrow keys 

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	cout << "Renderer:" << renderer << endl;
	cout << "OpenGL version supported:" << version << endl;
	// "MENU"
	cout << "Coordenadas da Luz (x e y) - setas para alterar" << endl;

	glutMainLoop();                   // Enter the infinite event-processing loop
	return 0;
}