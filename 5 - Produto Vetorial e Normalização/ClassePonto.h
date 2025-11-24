#pragma once
#include <math.h>
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h

class Ponto {
public:
	int Id;
	float x;
	float y;
	float z;
public:
	Ponto();
	Ponto(int tId, float tx, float ty, float tz);
	void Desenha();
};