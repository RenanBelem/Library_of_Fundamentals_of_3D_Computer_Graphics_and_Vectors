/// MS VS
#include <GL\glew.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
using namespace std;

#include "ClasseVetor.cpp"

/* Global variables */
char title[] = "OpenGL-PUC PR - Aplicação usando Vetores)";
GLfloat nRange = 200;
GLfloat anglex = 0.0f, angley = 0.0f, anglez = 0.0f, zoom = 1.0f;

Vetor posicao(1, 0.0f, 0.0f, 0.0f);
Vetor velocidade(2, 1.5f, 2.1f, 1.0f);
Vetor gravidade(3, 0.0f, -0.2f, 0.0f);


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

	glColor3f(0.8f, 0.8f, 0.8f);
	glutWireCube(2 * nRange); // volume de vilsualização
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
	case GLUT_KEY_PAGE_UP:  // rotação eixo x
		anglez--;
		break;
	case GLUT_KEY_PAGE_DOWN:  // rotação eixo x
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
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_FLAT);     // Enable flat shading
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

void cubo(float a, float xpos, float ypos, float zpos)    // Cubo posicionado em xpos, ypos, zpos
{
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f); // red
	glVertex3f(-a / 2 + xpos, a / 2 + ypos, a / 2 + zpos);
	glVertex3f(-a / 2 + xpos, -a / 2 + ypos, a / 2 + zpos);
	glColor3f(0.0f, 0.0f, 1.0f); // blue
	glVertex3f(a / 2 + xpos, a / 2 + ypos, a / 2 + zpos);
	glVertex3f(a / 2 + xpos, -a / 2 + ypos, a / 2 + zpos);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glVertex3f(a / 2 + xpos, a / 2 + ypos, -a / 2 + zpos);
	glVertex3f(a / 2 + xpos, -a / 2 + ypos, -a / 2 + zpos);
	glColor3f(1.0f, 1.0f, 0.0f); // magenta
	glVertex3f(-a / 2 + xpos, a / 2 + ypos, -a / 2 + zpos);
	glVertex3f(-a / 2 + xpos, -a / 2 + ypos, -a / 2 + zpos);
	glColor3f(1.0f, 0.0f, 1.0f); // cyan
	glVertex3f(-a / 2 + xpos, a / 2 + ypos, a / 2 + zpos);
	glVertex3f(-a / 2 + xpos, -a / 2 + ypos, a / 2 + zpos);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.5f, 0.5f, 0.5f); // grey
	glVertex3f(-a / 2 + xpos, a / 2 + ypos, -a / 2 + zpos);
	glVertex3f(-a / 2 + xpos, a / 2 + ypos, a / 2 + zpos);
	glVertex3f(a / 2 + xpos, a / 2 + ypos, -a / 2 + zpos);
	glVertex3f(a / 2 + xpos, a / 2 + ypos, a / 2 + zpos);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 0.5f, 0.0f); // orange
	glVertex3f(a / 2 + xpos, -a / 2 + ypos, -a / 2 + zpos);
	glVertex3f(a / 2 + xpos, -a / 2 + ypos, a / 2 + zpos);
	glVertex3f(-a / 2 + xpos, -a / 2 + ypos, -a / 2 + zpos);
	glVertex3f(-a / 2 + xpos, -a / 2 + ypos, a / 2 + zpos);
	glEnd();
}

// animação - variáveis que alteram a cena
void update(int value) {
	// Adição do vetor velocidade ao vetor posicao
	posicao.SomaVetor(velocidade);
	// Adição do vetor gravidade ao vetor velocidade
	velocidade.SomaVetor(gravidade);
	// Verifica a colisão com os limites (inverte o vetor correspondente)
	if ((posicao.xcomp > nRange) || (posicao.xcomp < -nRange)) { // colisão é centro do cubo
		velocidade.xcomp = velocidade.xcomp * -1;
	}
	if ((posicao.zcomp > nRange) || (posicao.zcomp < -nRange)) {
		velocidade.zcomp = velocidade.zcomp * -1;
	}
	if ((posicao.ycomp > nRange) || (posicao.ycomp < -nRange)) {
		// Redução da velocidade quando colisão com o "chão"
		velocidade.ycomp = velocidade.ycomp * -0.95;
		posicao.ycomp = -nRange;
	}
	glutPostRedisplay(); // Informa a GLUT que o "display" foi alterado
	glutTimerFunc(25, update, 0);//Chama a função update após cada 25 milisegundos
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

	grid();

	cubo(50, posicao.xcomp, posicao.ycomp, posicao.zcomp);
	
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
	glutTimerFunc(25, update, 0);	  // Ragistra a função update como a ser atualizada pela função Timer a cada 25 msec
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