#include <math.h>
#include <GL\freeglut.h>
#include "Triangle.h"
#include "Disk.h"

#include <iostream>		  // for "cout <<"
using namespace std;

Disk::Disk(int idC, float ppcx, float ppcy, float ppcz, float aa)
{
	pcx = ppcx;
	pcy = ppcy;
	pcz = ppcz;
	a = aa;
	id = idC;


	float angulo = 0.0f;
	// Base como um triângulo equilátero com o centro na origem e altura "a"

}

void Disk::Desenha()

{
	glPolygonMode(GL_BACK, GL_LINE); //desenha faces posteriores somente com arestas
	glPolygonMode(GL_FRONT, GL_FILL); //desenha faces frontais com só´lida
	glPushMatrix();
	glTranslatef(pcx, pcy, pcz);
	float angulo = 0.0f;
	float x = 0.0f, y = 0.0f, z = 0.0f;
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0.0f, 0.0f, 1.0f);// o vetor normal,neste caso,é óbvio:z positivo
	glVertex3f(x, y, z);
	while (angulo <= 2.01 * PI) { // 2.01 é para forçar o desenho o último triângulo
		angulo = angulo + PI / 36;
		x = 20 * cos(angulo);
		y = 20 * sin(angulo);
		glVertex3f(x, y, z);

	}
	glEnd();
	// desenha o vetor normal
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 20.0f);
	glEnd();
	glPopMatrix();

}
Disk::~Disk() {}

