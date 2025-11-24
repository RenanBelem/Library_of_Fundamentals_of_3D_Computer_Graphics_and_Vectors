/// MS VS
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include "Matriz4q.h"
#include "Objeto.h"

using namespace std;

/* Global variables */
char title[] = "OpenGL - PUC PR >> MATRIZES 1 - TRANSFORMAÇÕES GEOMÉTRICAS NO ESPAÇO - OBJETO DEFINIDO POR COORDENADAS";
GLfloat nRange = 200;
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

float data2[13][4] = {    {100, 150, 10, 1},		// coordenadas homogêneas do objeto (Ob1)
						  {150, 150, 10, 1},
						  {200, 100, 10, 1},
						  {250, 150, 10, 1},
						  {300, 150, 10, 1},
						  {250, 200, 10, 1},
						  {300, 250, 10, 1},
						  {250, 250, 10, 1},
						  {200, 300, 10, 1},
						  {150, 250, 10, 1},
						  {100, 250, 10, 1},
						  {150, 200, 10, 1},
						  {100, 150, 10, 1} };

Matriz4q M_A;
Matriz4q M_B;

Matriz4q M_T1, M_T2, M_T3;
Matriz4q M_data1(data1);

Objeto Ob1(13, data2);

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
}
// Função usada para especificar o volume de visualização
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
		
	cor("BRANCO");	
	Ob1.Desenha();		// objeto Original
	
	// transformações	-- Obs. as operações se acumulam, aqui não resolve glPushMatrix/glPopMatrix
	// o objeto é modificado efetivamente nas suas coordenadas
	// a cada chamada da função render() o objeto é modificado, neste caso sofre a escala de redução 
	// continuamente. 

	// Escala Relativa ao centro do objeto
	M_T1.Translacao(-200.0f, -200.0f, 0.0f);
	M_T2.Escala(0.5f, 0.5f, 0.5f);	
	M_T3.Translacao(200.0f, 200.0f, 0.0f);
	M_T1.Multiplica(M_T2);
	M_T1.Multiplica(M_T3);

	Ob1.Transforma(M_T1); 
	cor("AMARELO");	
	Ob1.Desenha();		// Objeto Transformado

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);             // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE);  // Enable double buffered mode
	glutInitWindowSize(640, 480);      // Set the window's initial width & height
	glutInitWindowPosition(350, 50);    // Position the window's initial top-left corner
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
	// "MENU"
	cout << "Projecao Perspectiva" << endl;
	cout << "Eixo X em Vermelho" << endl;
	cout << "Eixo Y em Verde" << endl;
	cout << "Eixo Z em Azul" << endl;
	cout << "Interacao:" << endl;
	cout << "Mouse: botao esquerdo zoom in, direito zoom out" << endl;
	cout << "Teclado: setas rotacao da cena (eixos X e Y)" << endl;
	cout << "Teclado: teclas ASWZ reposiciona o Observador (eixos X e Y)" << endl;
	cout << "Teclado: tecla R reseta para a projecao inicial" << endl;

	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}