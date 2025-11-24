#include "Objeto.h"

Objeto::Objeto() // inicializa o array de coordenadas
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = 0.0f;
	nV = 0;
}

Objeto::Objeto(int tnV, float tdata[100][4])
{
	nV = tnV;
	for (int i = 0; i < nV; i++)
		for (int j = 0; j < 4; j++)
			data[i][j] = tdata[i][j];
}

void Objeto::Desenha()
{
	glBegin(GL_LINE_STRIP);
		for (int i = 0; i < nV; i++)
			glVertex3f(data[i][0], data[i][1], data[i][2]);
	glEnd();
}

void Objeto::Print()
{
	for (int i = 0; i < nV; i++)
		for (int j = 0; j < 4; j++)
			cout << "[" << i << "][" << j << "]=" << data[i][j] << endl;
}

void Objeto::Transforma(Matriz4q MT) 
{
	float temp1 = 0.0f;  // variável auxiliar para armazenar o cálculo da multiplicação da linha pela coluna
	float temp2[100][4]; // array auxiliar para armazenar temporariamente a matriz resultado

	for (int i = 0; i < 100; i++)		// inicializando a matriz temporária (temp2)
		for (int j = 0; j < 4; j++)
			temp2[i][j] = 0.0f;

	for (int i = 0; i < nV; i++)        // cálculo da multiplicação das matrizes - colocando na matriz temporária (temp2)
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) 
				temp1 = temp1 + data[i][k] * MT.data[k][j];
			temp2[i][j] = temp1;
			temp1 = 0.0f;
		}

	for (int i = 0; i < nV; i++)		// passando os cálculos feitos (temp2) para o objeto que invocou o método
		for (int j = 0; j < 4; j++)
			data[i][j] = temp2[i][j];
}

Objeto::~Objeto()
{

}
