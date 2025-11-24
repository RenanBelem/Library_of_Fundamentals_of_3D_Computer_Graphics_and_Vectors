#include <math.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include "ClassePonto.h"

Ponto::Ponto() {}

Ponto::Ponto(int tId, float tx, float ty, float tz) {
	Id = tId;
	x = tx;
	y = ty;
	z = tz;
}

void Ponto::Desenha() {
	glPushMatrix();
		glTranslatef(x, y, z);
		glutSolidSphere(5, 5, 5);
	glPopMatrix();
}