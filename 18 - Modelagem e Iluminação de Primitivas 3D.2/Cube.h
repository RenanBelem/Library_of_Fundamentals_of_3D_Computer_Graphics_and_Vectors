#pragma once
# define PI 3.141592653589793238462643383279502884L /* pi */
class Cube
{
public:
	float pcx, pcy, pcz;
	float a;       // aresta
	int id;
	float t1[3][3]; // triângulo que forma a face 1 (3 vértices - x,y,z)
	float t2[3][3];
	float t3[3][3];
	float t4[3][3];
	float t5[3][3]; // triângulo que forma a face 1 (3 vértices - x,y,z)
	float t6[3][3];
	float t7[3][3];
	float t8[3][3];
	float t9[3][3]; // triângulo que forma a face 1 (3 vértices - x,y,z)
	float t10[3][3];
	float t11[3][3];
	float t12[3][3];


public:
	Cube(int idC, float ppcx, float ppcy, float ppcz, float aa);
	void Desenha();
	~Cube();
};



