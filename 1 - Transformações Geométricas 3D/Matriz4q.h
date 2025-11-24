#pragma once
#include <iostream>

# define PI 3.141592653589793238462643383279502884L /* pi */

using namespace std;

class Matriz4q
{
public:
	float data[4][4];			// 4x4 array
public:
	Matriz4q();					// cria a matriz com seus elementos iguais a zero
	Matriz4q(float data[4][4]); // cria a matriz com num array de dados
	void Identidade();			// transforma em matriz identidade
	void Transposta();			// transforma em matriz transposta
	void Soma(Matriz4q M);		// soma com a matriz M
	void Subtrai(Matriz4q M);	// subtrai a matriz M
	void Multiplica(Matriz4q M);// multiplica pela matriz M
	void MultiplicaEscalar(float k); // multiplica por um escalar
	void Print();				// imprime os valores da matriz no console
	void Translacao(float dx, float dy, float dz); // alimenta a matriz como Translação
	void Escala(float sx, float sy, float sz); // alimenta a matriz como 
	void RotacaoX(float angulo); // alimenta a matriz como rotação em X
	void RotacaoY(float angulo); // alimenta a matriz como rotação em Y
	void RotacaoZ(float angulo); // alimenta a matriz como rotação em Z
	~Matriz4q();
};

