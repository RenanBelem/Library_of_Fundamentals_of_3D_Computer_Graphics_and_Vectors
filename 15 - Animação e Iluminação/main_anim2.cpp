/// MS VS 
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
using namespace std;

/* Global variables */
char title[] = "OpenGL-PUC PR (ANIMAÇÃO COM INTERAÇÃO - TESTE DE PROFUNDIDADE)";
GLfloat nRange = 20;
GLfloat angle = 0.0f, angle1 = 0.0f;

// Keyboard ... processamento das teclas especiais (setas)
void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		angle1 = angle1 - 0.5f;
		break;
	case GLUT_KEY_RIGHT:
		angle1 = angle1 + 0.5f;
		break;
	case GLUT_KEY_UP:
		angle = angle - 0.5f;
		break;
	case GLUT_KEY_DOWN:
		angle = angle + 0.5f;
		break;
	}
	glutPostRedisplay(); // força o redesenho da tela
}

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);              // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);               // Set the type of depth-test
	glShadeModel(GL_FLAT);                // Enable smooth shading
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);

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
	
	// Drawing Triangles
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 0.0);  // Yellow
		glVertex3f(0.0, 0.0, 15.0);
		glVertex3f(10.0, 0.0, 15.0);
		glVertex3f(5.0, 10.0, 15.0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);  // White
		glVertex3f(0.0, 0.0, 5.0);
		glVertex3f(10.0, 0.0, 5.0);
		glVertex3f(5.0, 10.0, 5.0);
	glEnd();

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
	if (w <= h)				// PROJEÇÃO ORTOGONAL
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);     // Set the window's initial width & height
	glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(render);          // Register callback handler for window re-paint event
	glutIdleFunc(render);
	glutReshapeFunc(reshape);         // Register callback handler for window re-size event
	glutSpecialFunc(processSpecialKeys);  // Register callback handler for arrow keys 
	initGL();                         // Our own OpenGL initialization

    // start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	cout << "Eixo X em Vermelho" << endl;
	cout << "Eixo Y em Verde" << endl;
	cout << "Eixo Z em Azul" << endl;
	cout << "Interacao:" << endl;
	cout << "Teclado: setas rotacao da cena em X e Y" << endl;

	glutMainLoop();                   // Enter the infinite event-processing loop
	return 0;
}
