#include <math.h>
#include <GL\freeglut.h>
#include "Triangle.h"
#include "Cone.h"
#include <iostream>          
using namespace std;

Cone::Cone(int idC, float ppcx, float ppcy, float ppcz, float aa)
{
    pcx = ppcx;
    pcy = ppcy;
    pcz = ppcz;
    a = aa;
    id = idC;


    //float angulo = 0.0f;
    // Base como um triângulo equilátero com o centro na origem e altura "a"

}

void Cone::Desenha()

{
    glPolygonMode(GL_BACK, GL_LINE);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPushMatrix();
    glTranslatef(pcx, pcy, pcz);
    glFrontFace(GL_CW);
    float angulo = 0.0f;
    float x = 0.0f, y = 0.0f, z = 0.0f;
    float raio = 20.0f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z);
    while (angulo <= 2.01 * PI)
    {
        angulo = angulo + PI / 36;
        x = raio * cos(angulo);
        y = raio * sin(angulo);
        glVertex3f(x, y, z);
    }

    glEnd();
    glFrontFace(GL_CCW);

    angulo = 0.0f;
    x = 0.0f, y = 0.0f, z = 0.0f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, 20);
    while (angulo <= 2.01 * PI)
    {
        angulo = angulo + PI / 36;
        x = raio * cos(angulo);
        y = raio * sin(angulo);
        glVertex3f(x, y, z);
    }
    // desenha o vetor normal
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 20.0f);
    glEnd();
    glPopMatrix();
}
Cone::~Cone() {}
