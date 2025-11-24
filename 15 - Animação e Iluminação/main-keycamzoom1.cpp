/// MS VS
#include <windows.h>      // for MS Windows
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>
#include <iostream>
using namespace std;

/* Global variables */
char title[] = "OpenGL-PUC PR (PROJEÇÃO ORTOGONAL: ZOOM - MOUSE / ROTAÇÃO - SETAS) 1";
GLfloat nRange = 200;
GLfloat angle = 0.0f, angle1 = 0.0f;
GLfloat zoom = 1.0f;

void desenhaEixos() {
	// Drawing XYZ Axis
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0); // Red - X (to rigth)
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(+nRange, 0.0, 0.0);
		glColor3f(0.0, 1.0, 0.0); // Green - Y (to up)
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, +nRange, 0.0);
		glColor3f(0.0, 0.0, 1.0); // Blue - Z (leaving the screen)
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, +nRange);
	glEnd();
}

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
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
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			 zoom += 0.1;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			 zoom -= 0.1;
		}
	glutPostRedisplay();
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);			// To operate on model-view matrix
	glLoadIdentity();					// Reset the model-view matrix

	glRotatef(angle, 1.0f, 0.0f, 0.0f); // rotação da cena em x
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);// rotação da cena em y
	glScalef(zoom, zoom, zoom);			// truque para termos o Zoom 

	desenhaEixos();

	glutWireTeapot(100);

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
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
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
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
//	glutIdleFunc(render);		   // Register callback handler for window redraw 
	glutSpecialFunc(processSpecialKeys);  // Register callback handler for arrow keys 
	glutMouseFunc(mouse);
	initGL();  // Our own OpenGL initialization

		// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	cout << "Renderer:" << renderer << endl;
	cout << "OpenGL version supported:" << version << endl;
	cout << "Projecao Ortogonal" << endl;
	cout << "Eixo X em Vermelho" << endl;
	cout << "Eixo Y em Verde" << endl;
	cout << "Eixo Z em Azul" << endl;
	cout << "Interacao:" << endl;
	cout << "Mouse: botao esquerdo zoom in, botao direito zoom out, setas rotacao em X e Y" << endl;
	cout << "Teclado: setas rotacao da cena em X e Y" << endl;

	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;

}