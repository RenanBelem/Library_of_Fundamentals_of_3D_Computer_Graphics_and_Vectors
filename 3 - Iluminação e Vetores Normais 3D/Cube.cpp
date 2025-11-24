#include <math.h>
#include <GL\freeglut.h>
#include "Triangle.h"
#include "Cube.h"

#include <iostream>		  // for "cout <<"
using namespace std;

Cube::Cube(int idC, float ppcx, float ppcy, float ppcz, float aa)
{
	pcx = ppcx;
	pcy = ppcy;
	pcz = ppcz;
	a = aa;
	id = idC;

	float angulo = 30.0f*PI / 180.0f; 

	t1[0][0] = -a;            t1[0][1] = -a;           t1[0][2] = -a;    // Face 1
	t1[1][0] = -a;			  t1[1][1] = -a;	       t1[1][2] =  a;
	t1[2][0] = -a;			  t1[2][1] =  a;		   t1[2][2] =  a;

	t2[0][0] =  a;            t2[0][1] =  a;		   t2[0][2] = -a;    // Face 2
	t2[1][0] = -a;            t2[1][1] = -a;           t2[1][2] = -a;
	t2[2][0] = -a;			  t2[2][1] =  a;		   t2[2][2] = -a;

	t3[0][0] =  a;            t3[0][1] =  -a;          t3[0][2] =  a;    // Face 3 
	t3[1][0] = -a;			  t3[1][1] =  -a;		   t3[1][2] = -a;
	t3[2][0] =  a;            t3[2][1] =  -a;          t3[2][2] = -a;

	t4[0][0] = a;             t4[0][1] =  a;           t4[0][2] = -a; // Face 4, Base
	t4[1][0] = a;			  t4[1][1] = -a;	       t4[1][2] = -a;
	t4[2][0] =-a;			  t4[2][1] = -a;		   t4[2][2] = -a;

	t5[0][0] = -a;            t5[0][1] = -a;           t5[0][2] = -a;    // Face 5
	t5[1][0] = -a;			  t5[1][1] =  a;		   t5[1][2] =  a;
	t5[2][0] = -a;		      t5[2][1] =  a;		   t5[2][2] = -a;

	t6[0][0] = a;              t6[0][1] = -a;          t6[0][2] =  a;    // Face 6
	t6[1][0] = -a;             t6[1][1] = -a;          t6[1][2] =  a;
	t6[2][0] = -a;			   t6[2][1] = -a;		   t6[2][2] = -a;
	 
	t7[0][0] = -a;             t7[0][1] =  a;          t7[0][2] = a;    // Face 7 
	t7[1][0] = -a;			   t7[1][1] = -a;		   t7[1][2] = a;
	t7[2][0] =  a;             t7[2][1] = -a;          t7[2][2] = a;

	t8[0][0] = a;              t8[0][1] = a;           t8[0][2] =  a; // Face 8
	t8[1][0] = a;			   t8[1][1] = -a;		   t8[1][2] = -a;
	t8[2][0] = a;		       t8[2][1] = a;		   t8[2][2] = -a;

	t9[0][0] = a;              t9[0][1] = -a;          t9[0][2] = -a;    // Face 9
	t9[1][0] = a;			   t9[1][1] = a;		   t9[1][2] =  a;
	t9[2][0] = a;			   t9[2][1] = -a;		   t9[2][2] =  a;

	t10[0][0] =  a;            t10[0][1] = a;          t10[0][2] =  a;    // Face 10
	t10[1][0] =  a;            t10[1][1] = a;          t10[1][2] = -a;
	t10[2][0] = -a;			   t10[2][1] = a;		   t10[2][2] = -a;

	t11[0][0] =  a;            t11[0][1] = a;          t11[0][2] = a;    // Face 11 
	t11[1][0] = -a;			   t11[1][1] = a;		   t11[1][2] = -a;
	t11[2][0] = -a;            t11[2][1] = a;          t11[2][2] = a;

	t12[0][0] =  a;            t12[0][1] = a;           t12[0][2] = a; // Face 12
	t12[1][0] = -a;			   t12[1][1] = a;			t12[1][2] = a;
	t12[2][0] =  a;			   t12[2][1] = -a;			t12[2][2] = a;

}



void Cube::Desenha()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  // desenha faces posteriores somente com arestas
	glPushMatrix();
	glTranslatef(pcx, pcy, pcz);

	glBegin(GL_TRIANGLES);
		Triangle f1(1,t1);		// face 1
		glNormal3fv(f1.normal);
		glVertex3fv(t1[0]);
		glVertex3fv(t1[1]);
		glVertex3fv(t1[2]);
	
		Triangle f2(1, t2);		// face 2
		glNormal3fv(f2.normal);
		glVertex3fv(t2[0]);
		glVertex3fv(t2[1]);
		glVertex3fv(t2[2]);

		Triangle f3(1, t3);		// face 3
		glNormal3fv(f3.normal);
		glVertex3fv(t3[0]);
		glVertex3fv(t3[1]);
		glVertex3fv(t3[2]);

		Triangle f4(1, t4);		// face 4
		glNormal3fv(f4.normal);
		glVertex3fv(t4[0]);
		glVertex3fv(t4[1]);
		glVertex3fv(t4[2]);
	glEnd();

	glBegin(GL_TRIANGLES);
	Triangle f5(1, t5);		// face 5
	glNormal3fv(f5.normal);
	glVertex3fv(t5[0]);
	glVertex3fv(t5[1]);
	glVertex3fv(t5[2]);

	Triangle f6(1, t6);		// face 6
	glNormal3fv(f6.normal);
	glVertex3fv(t6[0]);
	glVertex3fv(t6[1]);
	glVertex3fv(t6[2]);

	Triangle f7(1, t7);		// face 7
	glNormal3fv(f7.normal);
	glVertex3fv(t7[0]);
	glVertex3fv(t7[1]);
	glVertex3fv(t7[2]);

	Triangle f8(1, t8);		// face 8
	glNormal3fv(f8.normal);
	glVertex3fv(t8[0]);
	glVertex3fv(t8[1]);
	glVertex3fv(t8[2]);

	glEnd();

	glBegin(GL_TRIANGLES);
	Triangle f9(1, t9);		// face 9
	glNormal3fv(f9.normal);
	glVertex3fv(t9[0]);
	glVertex3fv(t9[1]);
	glVertex3fv(t9[2]);

	Triangle f10(1, t10);		// face 10
	glNormal3fv(f10.normal);
	glVertex3fv(t10[0]);
	glVertex3fv(t10[1]);
	glVertex3fv(t10[2]);

	Triangle f11(1, t11);		// face 11
	glNormal3fv(f11.normal);
	glVertex3fv(t11[0]);
	glVertex3fv(t11[1]);
	glVertex3fv(t11[2]);

	Triangle f12(1, t12);		// face 12
	glNormal3fv(f12.normal);
	glVertex3fv(t12[0]);
	glVertex3fv(t12[1]);
	glVertex3fv(t12[2]);
	glEnd();

	// desenha os vetores normais
	// cálculo do centro das faces
	// Face 1
	// centro da face
	float cf1x = (t1[0][0] + t1[1][0] + t1[2][0] ) / 3; //  média dos componentes em x
	float cf1y = (t1[0][1] + t1[1][1] + t1[2][1] ) / 3;
	float cf1z = (t1[0][2] + t1[1][2] + t1[2][2] ) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex3f(cf1x, cf1y, cf1z);
		glVertex3f(cf1x + f1.normal[0] * 10, cf1y + f1.normal[1] * 10, cf1z + f1.normal[2] * 10);
	glEnd();
	// Face 2
	float cf2x = (t2[0][0] + t2[1][0] + t2[2][0]) / 3; //  média dos componentes em x
	float cf2y = (t2[0][1] + t2[1][1] + t2[2][1]) / 3;
	float cf2z = (t2[0][2] + t2[1][2] + t2[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex3f(cf2x, cf2y, cf2z);
		glVertex3f(cf2x + f2.normal[0] * 10, cf2y + f2.normal[1] * 10, cf2z + f2.normal[2] * 10);
	glEnd();
	// Face 3
	float cf3x = (t3[0][0] + t3[1][0] + t3[2][0]) / 3; //  média dos componentes em x
	float cf3y = (t3[0][1] + t3[1][1] + t3[2][1]) / 3;
	float cf3z = (t3[0][2] + t3[1][2] + t3[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex3f(cf3x, cf3y, cf3z);
		glVertex3f(cf3x + f3.normal[0] * 10, cf3y + f3.normal[1] * 10, cf3z + f3.normal[2] * 10);
	glEnd();
	// Face 4
	float cf4x = (t4[0][0] + t4[1][0] + t4[2][0]) / 3; //  média dos componentes em x
	float cf4y = (t4[0][1] + t4[1][1] + t4[2][1]) / 3;
	float cf4z = (t4[0][2] + t4[1][2] + t4[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex3f(cf4x, cf4y, cf4z);
		glVertex3f(cf4x + f4.normal[0] * 10, cf4y + f4.normal[1] * 10, cf4z + f4.normal[2] * 10);
	glEnd();

	// Face 5
	// centro da face
	float cf5x = (t5[0][0] + t5[1][0] + t5[2][0]) / 3; //  média dos componentes em x
	float cf5y = (t5[0][1] + t5[1][1] + t5[2][1]) / 3;
	float cf5z = (t5[0][2] + t5[1][2] + t5[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf5x, cf5y, cf5z);
	glVertex3f(cf5x + f5.normal[0] * 10, cf5y + f5.normal[1] * 10, cf5z + f5.normal[2] * 10);
	glEnd();
	// Face 6
	float cf6x = (t6[0][0] + t6[1][0] + t6[2][0]) / 3; //  média dos componentes em x
	float cf6y = (t6[0][1] + t6[1][1] + t6[2][1]) / 3;
	float cf6z = (t6[0][2] + t6[1][2] + t6[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf6x, cf6y, cf6z);
	glVertex3f(cf6x + f6.normal[0] * 10, cf6y + f6.normal[1] * 10, cf6z + f6.normal[2] * 10);
	glEnd();
	// Face 7
	float cf7x = (t7[0][0] + t7[1][0] + t7[2][0]) / 3; //  média dos componentes em x
	float cf7y = (t7[0][1] + t7[1][1] + t7[2][1]) / 3;
	float cf7z = (t7[0][2] + t7[1][2] + t7[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf7x, cf7y, cf7z);
	glVertex3f(cf7x + f7.normal[0] * 10, cf7y + f7.normal[1] * 10, cf7z + f7.normal[2] * 10);
	glEnd();
	// Face 8
	float cf8x = (t8[0][0] + t8[1][0] + t8[2][0]) / 3; //  média dos componentes em x
	float cf8y = (t8[0][1] + t8[1][1] + t8[2][1]) / 3;
	float cf8z = (t8[0][2] + t8[1][2] + t8[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf8x, cf8y, cf8z);
	glVertex3f(cf8x + f8.normal[0] * 10, cf8y + f8.normal[1] * 10, cf8z + f8.normal[2] * 10);
	glEnd();

	// Face 9
	// centro da face
	float cf9x = (t9[0][0] + t9[1][0] + t9[2][0]) / 3; //  média dos componentes em x
	float cf9y = (t9[0][1] + t9[1][1] + t9[2][1]) / 3;
	float cf9z = (t9[0][2] + t9[1][2] + t9[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf9x, cf9y, cf9z);
	glVertex3f(cf9x + f9.normal[0] * 10, cf9y + f9.normal[1] * 10, cf9z + f9.normal[2] * 10);
	glEnd();
	// Face 10
	float cf10x = (t10[0][0] + t10[1][0] + t10[2][0]) / 3; //  média dos componentes em x
	float cf10y = (t10[0][1] + t10[1][1] + t10[2][1]) / 3;
	float cf10z = (t10[0][2] + t10[1][2] + t10[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf10x, cf10y, cf10z);
	glVertex3f(cf10x + f10.normal[0] * 10, cf10y + f10.normal[1] * 10, cf10z + f10.normal[2] * 10);
	glEnd();
	// Face 11
	float cf11x = (t11[0][0] + t11[1][0] + t11[2][0]) / 3; //  média dos componentes em x
	float cf11y = (t11[0][1] + t11[1][1] + t11[2][1]) / 3;
	float cf11z = (t11[0][2] + t11[1][2] + t11[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf11x, cf11y, cf11z);
	glVertex3f(cf11x + f11.normal[0] * 10, cf11y + f11.normal[1] * 10, cf11z + f11.normal[2] * 10);
	glEnd();
	// Face 12
	float cf12x = (t12[0][0] + t12[1][0] + t12[2][0]) / 3; //  média dos componentes em x
	float cf12y = (t12[0][1] + t12[1][1] + t12[2][1]) / 3;
	float cf12z = (t12[0][2] + t12[1][2] + t12[2][2]) / 3;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(cf12x, cf12y, cf12z);
	glVertex3f(cf12x + f12.normal[0] * 10, cf12y + f12.normal[1] * 10, cf12z + f12.normal[2] * 10);
	glEnd();

	glPopMatrix();
}

Cube::~Cube()
{
}
