#pragma once
# define PI 3.141592653589793238462643383279502884L /* pi */ 
#include <gl/freeglut.h>

class Cone
{
public:
	float pcx, pcy, pcz;
	float a;       // aresta
	int id;

public:
	Cone(int idC, float ppcx, float ppcy, float ppcz, float aa);
	void Desenha();
	~Cone();
};


