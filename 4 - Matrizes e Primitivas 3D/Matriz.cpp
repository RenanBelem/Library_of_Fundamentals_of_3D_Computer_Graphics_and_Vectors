/// MS VS
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include "Matriz4q.h"
#include "Matriz10q.h"

using namespace std;

/* Global variables */
char title[] = "OpenGL - PUC PR >> MATRIZES 0 - OPERAÇÕES";
GLfloat nRange = 400;
GLfloat angleV=120.0f, fAspect;
GLfloat angle = 0.0f, angle1 = 0.0f;
GLfloat obsX=0, obsY=0, obsZ=200;
GLfloat zNear = +100.0f;
GLfloat zFar = -100.0f;
GLfloat zCut = 0.0f;

float data1[4][4] = {	  {1,  0, 5, 0},		// dados para a inicialização de matriz
						  {2, -1, 0, 3},
						  {3,  0, 2, 0},
						  {7,  0, 6, 5} }; 

Matriz4q M_A;
Matriz4q M_B(data1);
Matriz4q M_C;
Matriz4q M_T;

Matriz10q M10_A(1);
Matriz10q M10_B(5);
Matriz10q M10_C;
Matriz10q M10_D(2);
Matriz10q M10_E(3);




void cor(std::string n_cor) {
	if (n_cor == "BRANCO") glColor3f(1.0f, 1.0f, 1.0f); else
		if (n_cor == "CINZA") glColor3f(0.5f, 0.5f, 0.5f); else
			if (n_cor == "VERMELHO") glColor3f(1.0f, 0.0f, 0.0f); else
				if (n_cor == "VERDE") glColor3f(0.0f, 1.0f, 0.0f); else
					if (n_cor == "AZUL") glColor3f(0.0f, 0.0f, 1.0f); else
						if (n_cor == "AMARELO") glColor3f(1.0f, 1.0f, 0.0f); else
							if (n_cor == "CIANO") glColor3f(0.0f, 1.0f, 1.0f); else
								if (n_cor == "MAGENTA") glColor3f(1.0f, 0.0f, 1.0f); else
									if (n_cor == "PRETO") glColor3f(0.0f, 0.0f, 0.0f);
}

void grid() {
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	cor("CINZA"); // grid
	for (int i = -nRange; i <= +nRange; i = i + 10) {
		glVertex3f(-nRange, float(i), 0.0f);
		glVertex3f(+nRange, float(i), 0.0f);

		glVertex3f(float(i), -nRange, 0.0f);
		glVertex3f(float(i), +nRange, 0.0f);
	}
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINES); // eixos
	cor("VERMELHO"); // vermelho eixo x
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(nRange / 2, 0.0f, 0.0f);
	cor("VERDE"); // verde eixo y
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, nRange / 2, 0.0f);
	cor("AZUL"); // azul eixo z
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, nRange / 2);
	glEnd();
	glLineWidth(1.0f);
}

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
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
	{
		// Especifica sistema de coordenadas de projeção
		glMatrixMode(GL_PROJECTION);
		// Inicializa sistema de coordenadas de projeção
		glLoadIdentity();
		// Especifica a projeção perspectiva
		gluPerspective(angleV, fAspect, zNear + zCut, zFar - zCut); // fovy, aspect ratio, zNear, zFar
		glMatrixMode(GL_MODELVIEW); // Especifica sistema de coordenadas do modelo
		glLoadIdentity(); 	        // Inicializa sistema de coordenadas do modelo
		// Especifica posição do observador e do alvo
		gluLookAt(obsX, obsY, obsZ, 0, 0, 0, 0, 1, 0); // eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ
	}
}
// Keyboard ...
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
	setVisParam();
	glutPostRedisplay();
}
void processRegularKey(unsigned char key, int xx, int yy) {
	switch (key) {
	case 'A':
	case 'a':
		obsX=obsX+10;
		break;
	case 'S':
	case 's':
		obsX=obsX-10;
		break;
	case 'W':
	case 'w':
		obsY=obsY+10;
		break;
	case 'Z':
	case 'z':
		obsY=obsY-10;
		break;
	case 'R':
	case 'r':
		angleV = 120.0f;
		angle = 0.0f, 
		angle1 = 0.0f;
		obsX = 0;
		obsY = 0;
		obsZ = 200;
		break;
	}
	setVisParam();
	glutPostRedisplay();
}
// Função callback chamada para gerenciar eventos do mouse
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angleV >= 10) angleV -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angleV <= 130) angleV += 5;
		}
	setVisParam();
	glutPostRedisplay();
}
/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei w, GLsizei h) {
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	setVisParam();
}
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

	glRotatef(angle, 1.0f, 0.0f, 0.0f);   // rotação no eixo x
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);  // rotação no eixo y

	grid();

	M10_A.Desenha(-300.0f, -300.0f, 0.0f);
	M10_B.Desenha( -50.0f,  -50.0f, 0.0f);
	M10_C.Desenha( 150.0f,  150.0f, 0.0f);
	M10_D.Desenha(-300.0f,  150.0f, 0.0f);
	M10_E.Desenha( 150.0f, -300.0f, 0.0f);


		
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);             // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE);  // Enable double buffered mode
	glutInitWindowSize(640, 480);      // Set the window's initial width & height
	glutInitWindowPosition(50, 50);    // Position the window's initial top-left corner
	glutCreateWindow(title);           // Create window with the given title
	glutDisplayFunc(render);           // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);          // Register callback handler for window re-size event
	glutSpecialFunc(processSpecialKeys);  // Register callback handler for arrow keys 
	glutKeyboardFunc(processRegularKey);  // Register callback handler for regular keys (A,S,W,Z e R)
	glutMouseFunc(mouse);                 // Register callback handler for mouse event
	initGL();                             // Our own OpenGL initialization

    // start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();



	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	cout << "Renderer:" << renderer << endl;
	cout << "OpenGL version supported:" << version << endl;

	// Operações Matriciais
	cout << "Matriz A" << endl;
	M_A.Print();
	cout << "Matriz B" << endl;
	M_B.Print();
	cout << "Matriz B Transposta" << endl;
	M_B.Transposta();
	M_B.Print();
	cout << "Matriz A como Indentidade" << endl;
	M_A.Identidade();
	M_A.Print();
	cout << "Matriz B = Matriz B x Matriz A" << endl;
	M_B.Multiplica(M_A);
	M_B.Print();
	cout << "Matriz B = Matriz B + Matriz A" << endl;
	M_B.Soma(M_A);
	M_B.Print();
	cout << "Matriz B multiplicada por 2.0" << endl;
	M_B.MultiplicaEscalar(2.0f);
	M_B.Print();
	cout << "Matriz B como Matriz de Escala Uniforme 50%" << endl;
	M_B.Escala(0.5f, 0.5f, 0.5f);
	M_B.Print();


	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}