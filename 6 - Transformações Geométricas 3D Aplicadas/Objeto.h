#pragma once
#include <GL\freeglut.h>        // GLUT, include glu.h and gl.h
#include <iostream>

#include "Matriz4q.h"

using namespace std;

class Objeto
{
public:
	float data[100][4];			// array de coordenadas
	int nV;						// número de vértices do objeto
public:
	Objeto();
	Objeto(int nV, float data[100][4]);
	void Desenha();
	void Print();
	void Transforma(Matriz4q M);
	~Objeto();
};

