#include <windows.h>      
#include <GL\glew.h>
#include <GL\freeglut.h>  
#include <iostream>		  
#include <string>
#include "Triangle.h"
#include "TetraHedro.h"
#include "Disk.h"
#include "Cube.h"
#include "Cone.h"
#include <tuple>
using namespace std;

TetraHedro th(1, -60.0f, -40.0f, -20.0f, 20.0f);
Cone cone(1, 60.0f, -40.0f, -40.0f, 10.0f);
Disk disk(1, -60.0f, 40.0f, 40.0f, 7.0f);
Cube cube(1, 60.0f, 40.0f, 20.0f, 10.0f);
typedef tuple<TetraHedro, Cone, Disk, Cube> tup;
tup t1 = make_tuple(th, cone, disk, cube);

char title[] = "TDE 3";

boolean grid_on = true;

GLfloat nRange = 500.0f;
GLfloat angleV = 45.0f, fAspect;
GLfloat angleX = 0.0f, angleY = 0.0f, angleZ;
GLfloat obsX = 0, obsY = 0, obsZ = 200;
GLfloat zNear = +100.0f;
GLfloat zFar = -100.0f;
GLfloat zCut = 0.0f;

GLfloat posicaoLuz[4] = { 0.0, 150.0, 500.0, 1.0 };




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

void setVisParam(void)
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

void reshape(GLsizei w, GLsizei h) {
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	setVisParam();
}

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		angleY--;
		break;
	case GLUT_KEY_RIGHT:
		angleY++;
		break;
	case GLUT_KEY_UP:
		angleX--;
		break;
	case GLUT_KEY_DOWN:
		angleX++;
		break;
	case GLUT_KEY_PAGE_UP:
		angleZ--;
		break;
	case GLUT_KEY_PAGE_DOWN:
		angleZ++;
		break;
	}
	setVisParam();
	glutPostRedisplay();
}
void processRegularKey(unsigned char key, int xx, int yy) {
	switch (key) {
	case 'D':
	case 'd':
		glEnable(GL_LIGHTING);
		break;
	case 'N':
	case 'n':
		glDisable(GL_LIGHTING);
		break;
	case 'G':
	case 'g':
		if (grid_on) grid_on = false; else grid_on = true;
		break;
	}
	setVisParam();
	glutPostRedisplay();
}
// Função callback chamada para gerenciar eventos do mouse
void mouse(int button, int state, int xx, int yy)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angleV >= 10) angleV -= 2;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angleV <= 130) angleV += 2;
		}
	setVisParam();
	glutPostRedisplay();
}

void initGL() {
	angleV = 45;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);			  // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);				  // Set the type of depth-test
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
	glShadeModel(GL_FLAT);
	//	glShadeModel(GL_SMOOTH);

	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.5,0.5,0.5,1.0 };
	GLfloat luzEspecular[4] = { 0.5,0.5,0.5,1.0 };

	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 40;
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
	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
}
void grid() {
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	cor("AMARELO"); // grid
	for (int i = -nRange; i <= +nRange; i = i + 10) {
		glVertex3f(-nRange, float(i), 0.0f);
		glVertex3f(+nRange, float(i), 0.0f);

		glVertex3f(float(i), -nRange, 0.0f);
		glVertex3f(float(i), +nRange, 0.0f);
	}
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINES); // eixos
	cor("VERMELHO"); // eixo x
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(nRange / 2, 0.0f, 0.0f);
	cor("VERMELHO"); // eixo y
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, nRange / 2, 0.0f);
	cor("VERMELHO"); // eixo z
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, nRange / 2);
	glEnd();
	glLineWidth(1.0f);
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

	if (grid_on) grid();

	cor("CINZA");
	get<0>(t1).Desenha();
	cor("CINZA");
	get<1>(t1).Desenha();
	cor("CINZA");
	get<2>(t1).Desenha();
	cor("CINZA");
	get<3>(t1).Desenha();
	cor("CINZA");
	glutSolidTeapot(25.0);

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);             // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // Define double buffered mode
	glutInitWindowSize(640, 480);      // Set the window's initial width & height
	glutInitWindowPosition(50, 50);    // Position the window's initial top-left corner
	glutCreateWindow(title);           // Create window with the given title
	glutDisplayFunc(render);           // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);          // Register callback handler for window re-size event
	glutSpecialFunc(processSpecialKeys);  // Register callback handler for arrow keys 
	glutKeyboardFunc(processRegularKey);
	glutMouseFunc(mouse);

	initGL();                           // Our own OpenGL initialization

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	cout << "Renderer:" << renderer << endl;
	cout << "OpenGL version supported:" << version << endl;
	cout << "Projecao Perspectiva" << endl;
	cout << "Interacao:" << endl;
	cout << "Botoes do mouse zoom in e zoom out" << endl;
	cout << "Rotacao dos eixos X e Y da cena com as setas" << endl;
	cout << "PgUp / PgDn rotacao do eixo Z da cena" << endl;
	cout << "D = Com luz / N = Sem luz" << endl;
	cout << "G = Grid" << endl;

	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}