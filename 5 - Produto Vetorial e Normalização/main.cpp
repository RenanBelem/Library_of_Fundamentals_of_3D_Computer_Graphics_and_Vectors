/// MS VS
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
using namespace std;

#include "ClasseVetor.h"
#include "ClassePonto.h"

/* Global variables */
char title[] = "OpenGL-PUC PR 'SandBox' para desenho e operação com Vetores)";
GLfloat nRange = 200;
GLfloat anglex = 0.0f, angley = 0.0f, anglez = 0.0f, zoom = 1.0f;

Ponto A(1, 0, 0, 100), B(2, 100, 0, 0), C(3, 0, 100, 0);
Vetor v1(1, 0.0, 0.0, 0.0), v2(2, 0.0f ,0.0 ,0.0), v3(3, 0.0, 0.0, 0.0), v5(4, 0.0, 0.0, 0.0);

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
	glColor3f(0.3f, 0.3f, 0.3f); // grid
	for (int i = -nRange; i <= +nRange; i = i + 10) {
		glVertex3f(-nRange, i,0.0f);
		glVertex3f(+nRange, i, 0.0f);

		glVertex3f(i, -nRange, 0.0f);
		glVertex3f(i, +nRange, 0.0f);
	}
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINES); // eixos
		glColor3f(0.5f, 0.0f, 0.0f); // vermelho eixo x
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(nRange / 2, 0.0f, 0.0f);
		glColor3f(0.0f, 0.5f, 0.0f); // verde eixo y
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, nRange / 2, 0.0f);
		glColor3f(0.0f, 0.0f, 0.5f); // azul eixo z
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, nRange / 2);
	glEnd();
	glLineWidth(1.0f);
}

// Keyboard ...
void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT: // rotação eixo y
		angley--;
		break;
	case GLUT_KEY_RIGHT: // rotação eixo y
		angley++;
		break;
	case GLUT_KEY_UP:   // rotação eixo x
		anglex--;
		break;
	case GLUT_KEY_DOWN:  // rotação eixo x
		anglex++;
		break;
	case GLUT_KEY_PAGE_UP:  // rotação eixo z
		anglez--;
		break;
	case GLUT_KEY_PAGE_DOWN:  // rotação eixo z
		anglez++;
		break;
	}
}
// Função callback chamada para gerenciar eventos do mouse
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			zoom += 0.1f;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			zoom -= 0.1f;
		}
	glutPostRedisplay();
}

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);
	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange*2, nRange*2);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange*2, nRange*2);
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	glLoadIdentity();                  // Reset the model-view matrix

	glRotatef(anglex, 1.0f, 0.0f, 0.0f);  // rotaciona ao redor de X (setas > e <)
	glRotatef(angley, 0.0f, 1.0f, 0.0f);  // rotaciona ao redor de Y (^ e v)
	glRotatef(anglez, 0.0f, 0.0f, 1.0f);  // rotaciona ao redor de Z (PgUp e PgDn)
	glScalef(zoom, zoom, zoom);

	v1.xcomp = B.x - A.x;
	v1.ycomp = B.y - A.y;
	v1.zcomp = B.z - A.z;

	v2.xcomp = C.x - B.x;
	v2.ycomp = C.y - B.y;
	v2.zcomp = C.z - B.z;

	v3.xcomp = A.x - C.x;
	v3.ycomp = A.y - C.y;
	v3.zcomp = A.z - C.z;

	grid();

	cor("AMARELO");
	v1.Desenha(0, 0, 100);
	cor("MAGENTA");
	v2.Desenha(100, 0, 0);
	cor("CIANO");
	v3.Desenha(0, 100, 0);
	cor("BRANCO");
	v5 = v5.ProdutoVetorial(v1, v2);
	v5.Normalizar();
	v5.MultEscalar(50.0);
	v5.Desenha((A.x + B.x + C.x)/3, (A.y + B.y + C.y)/3, (A.z + B.z + C.z)/3);

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {

	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);     // Set the window's initial width & height
	glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(render);          // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);         // Register callback handler for window re-size event
	glutIdleFunc(render);			  // Register callback handler for window redraw (keyboard event)
	glutSpecialFunc(processSpecialKeys);  // Register callback handler for arrow keys (keyborad)
	glutMouseFunc(mouse);                 // Register mouse function
	initGL();                             // Our own OpenGL initialization

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	cout << "Renderer:" << renderer << endl;
	cout << "OpenGL version supported:" << version << endl;

	cout << "Eixo X em Vermelho - rotacao com setas para cima e para baixo" << endl;
	cout << "Eixo Y em Verde    - rotacao com setas para esquerda e direita" << endl;
	cout << "Eixo Z em Azul     - rotacao com PgUp e PgDn" << endl;
	cout << "Mouse botao esquerdo - zoom in" << endl;
	cout << "Mouse botao direito  - zoom out" << endl;

	glutMainLoop();					// Enter the infinite event-processing loop
	return 0;
}