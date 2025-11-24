#include "Matriz4q.h"
#include <math.h>

Matriz4q::Matriz4q()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = 0.0f;
}

Matriz4q::Matriz4q(float tdata[4][4]) 
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = tdata[i][j];
}
void Matriz4q::Print() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cout << "[" << i << "][" << j << "]=" << data[i][j] << endl;
}
void Matriz4q::Identidade() 
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i==j) data[i][j] = 1; else data[i][j] = 0;
}

void Matriz4q::Transposta()
{
	Matriz4q Temp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			Temp.data[j][i] = data[i][j];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = Temp.data[i][j];
}

void Matriz4q::Soma(Matriz4q M)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = data[i][j] + M.data[i][j];
}

void Matriz4q::Subtrai(Matriz4q M)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = data[i][j] - M.data[i][j];
}

void Matriz4q::Multiplica(Matriz4q M)
{
	float temp[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for ( int k = 0; k < 4; k++)
			temp[i][j] += data[i][k] * M.data[k][j];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = temp[i][j];
}

void Matriz4q::MultiplicaEscalar(float k)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = k * data[i][j];
}

void Matriz4q::Translacao(float dx, float dy, float dz)
{
	data[0][0] = 1.0f; data[0][1] = 0.0f; data[0][2] = 0.0f; data[0][3] = 0.0f; 	
	data[1][0] = 0.0f; data[1][1] = 1.0f; data[1][2] = 0.0f; data[1][3] = 0.0f;
	data[2][0] = 0.0f; data[2][1] = 0.0f; data[2][2] = 1.0f; data[2][3] = 0.0f;
	data[3][0] = dx;   data[3][1] = dy;   data[3][2] = dz;   data[3][3] = 1.0f;
}

void Matriz4q::Escala(float sx, float sy, float sz)
{
	data[0][0] = sx;   data[0][1] = 0.0f; data[0][2] = 0.0f; data[0][3] = 0.0f;
	data[1][0] = 0.0f; data[1][1] = sy;   data[1][2] = 0.0f; data[1][3] = 0.0f;
	data[2][0] = 0.0f; data[2][1] = 0.0f; data[2][2] = sz;   data[2][3] = 0.0f;
	data[3][0] = 0.0f; data[3][1] = 0.0f; data[3][2] = 0.0f; data[3][3] = 1.0f;
}

void Matriz4q::RotacaoX(float angulo)
{
	angulo = angulo * PI / 180.0f;
	data[0][0] = 1.0f;   data[0][1] =  0.0f;         data[0][2] = 0.0f;        data[0][3] = 0.0f;
	data[1][0] = 0.0f;   data[1][1] =  cos(angulo);  data[1][2] = sin(angulo); data[1][3] = 0.0f;
	data[2][0] = 0.0f;   data[2][1] = -sin(angulo);  data[2][2] = cos(angulo); data[2][3] = 0.0f;
	data[3][0] = 0.0f;   data[3][1] =  0.0f;         data[3][2] = 0.0f;        data[3][3] = 1.0f;
}

void Matriz4q::RotacaoY(float angulo)
{
	angulo = angulo * PI / 180.0f;
	data[0][0] = cos(angulo);   data[0][1] = sin(angulo);  data[0][2] = 0.0f; data[0][3] = 0.0f;
	data[1][0] = -sin(angulo);  data[1][1] = cos(angulo);  data[1][2] = 0.0f; data[1][3] = 0.0f;
	data[2][0] = 0.0f;          data[2][1] = 0.0f;         data[2][2] = 1.0f; data[2][3] = 0.0f;
	data[3][0] = 0.0f;          data[3][1] = 0.0f;         data[3][2] = 0.0f; data[3][3] = 1.0f;
}

void Matriz4q::RotacaoZ(float angulo)
{
	angulo = angulo * PI / 180.0f;
	data[0][0] =  cos(angulo);   data[0][1] =  sin(angulo);  data[0][2] = 0.0f; data[0][3] = 0.0f;
	data[1][0] = -sin(angulo);   data[1][1] =  cos(angulo);  data[1][2] = 0.0f; data[1][3] = 0.0f;
	data[2][0] =  0.0f;          data[2][1] =  0.0f;         data[2][2] = 1.0f; data[2][3] = 0.0f;
	data[3][0] =  0.0f;          data[3][1] =  0.0f;         data[3][2] = 0.0f; data[3][3] = 1.0f;
}

Matriz4q::~Matriz4q()
{
}
