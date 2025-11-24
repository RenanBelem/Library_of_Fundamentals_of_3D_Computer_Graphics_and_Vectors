/// MS VS 
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
using namespace std;

GLfloat angleV, fAspect;
char title[] = "OpenGL-PUC PR: TETRAHEDROS - TRIÂNGULOS E SUAS NORMAIS";

GLfloat posicaoLuz[4] = { 0.0f, 150.0f, 500.0f, 1.0f };

GLfloat angle = 0.0f, angle1 = 0.0f;

void normaliza(float vector[3]) // normalização do vetor
{
	float length;
	//	Cálculo do comprimento do vetor
	length = (float)sqrt(pow(vector[0], 2.0) + pow(vector[1], 2.0) + pow(vector[2], 2.0));
	// Evita divisão por zero
	if (length == 0.0f) length = 1.0f;
	// Divide cada elemento pelo comprimento do vetor
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}

void calcNormal(float v[3][3], float out[3])
{
	float v1[3], v2[3];
	static const int x = 0; static const int y = 1; static const int z = 2;

	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	out[x] = v1[y] * v2[z] - v1[z] * v2[y];
	out[y] = v1[z] * v2[x] - v1[x] * v2[z];
	out[z] = v1[x] * v2[y] - v1[y] * v2[x];

	normaliza(out); // vetor unitário
}

void tetraHedro1() // SEM cálculo dos vetores normais
{
	glBegin(GL_TRIANGLES);
	{
		float v[3][3] = { { 0.0f, 25.0f,  0.0f },    // base em XY (face 1) (P1)
						{  25.0f, -25.0f, 0.0f },    // face 1 P2
						{ -25.0f, -25.0f, 0.0f } };  // face 1 P3
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	{
		float v[3][3] = { { -25.0f, -25.0f, 0.0f},   // face 2
						{    25.0f, -25.0f, 0.0f},
						{    0.0f, 0.0f,   50.0f} };
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	{
		float v[3][3] = { { 25.0f, -25.0f, 0.0f },   // face 3
						 {   0.0f,  25.0f, 0.0f },
						 {   0.0f, 0.0f,  50.0f } };
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	{
		float v[3][3] = { {  0.0f,  25.0f, 0.0f },     // face 4
						 { -25.0f, -25.0f, 0.0f },
						 {   0.0f,   0.0f, 50.0f } };
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	glEnd();
}
void tetraHedro2() // COM cálculo dos vetores normais
{
	float normal[3];
	glBegin(GL_TRIANGLES);
	{
		float v[3][3] = { {0.0f,   25.0f, 0.0f },    // base em XY(face 1) (P1)
						{  25.0f, -25.0f, 0.0f },    // face 1 P2
						{ -25.0f, -25.0f, 0.0f } };  // face 1 P3
		calcNormal(v, normal);
		glNormal3fv(normal);
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	{
		float v[3][3] = { { -25.0f, -25.0f, 0.0f},   // face 2
						{    25.0f, -25.0f, 0.0f},
						{    0.0f, 0.0f,   50.0f} };
		calcNormal(v, normal);
		glNormal3fv(normal);
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	{
		float v[3][3] = { { 25.0f, -25.0f, 0.0f },   // face 3
						 {   0.0f,  25.0f, 0.0f },
						 {   0.0f, 0.0f,  50.0f } };
		calcNormal(v, normal);
		glNormal3fv(normal);
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	{
		float v[3][3] = { {  0.0f,  25.0f,  0.0f },   // face 4
						 { -25.0f, -25.0f,  0.0f },
						 {   0.0f,   0.0f, 50.0f } };
		calcNormal(v, normal);
		glNormal3fv(normal);
		glVertex3fv(v[0]);
		glVertex3fv(v[1]);
		glVertex3fv(v[2]);
	}
	glEnd();
}

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
	glShadeModel(GL_SMOOTH);
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
	gluLookAt(0.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ
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

	glColor3f(1.0f, 0.0f, 0.0f);        // sem cálculo das normais - Vermelho
	glTranslatef(-50.0f, 0.0f, 0.0f);
	tetraHedro1();

	glColor3f(0.0f, 0.0f, 1.0f);        // com cálculo das normais - Azul
	glTranslatef(100.0f, 0.0f, 0.0f);
	tetraHedro2();

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
	cout << "Teclado: setas rotacao da cena em X e Y" << endl;

	glutMainLoop();                   // Enter the infinite event-processing loop
	return 0;
}