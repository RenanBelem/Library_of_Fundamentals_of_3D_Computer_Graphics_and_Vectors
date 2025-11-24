#include "Matriz10q.h"
#include <gl/glew.h>
#include <gl/freeglut.h>

#include <iostream>

Matriz10q::Matriz10q()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            data[i][j].red   = 0.0f;
            data[i][j].green = 0.0f;
            data[i][j].blue  = 0.0f;
        }

}

void Matriz10q::Desenha(float xpos, float ypos, float zpos)
{
    glPushMatrix();
    glTranslatef(xpos, ypos, zpos);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
       {
            glPushMatrix();
                glColor3f(data[i][j].red, data[i][j].green, data[i][j].blue);
                //glColor3f(1.0f, 0.0f, 0.0f);
                glTranslatef(i * 20, j * 20, 0.0f);
                glutSolidCube(18.0f);
            glPopMatrix();

        }
    glPopMatrix();
}



Matriz10q::Matriz10q(int CC)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            switch (CC) {
            case 1: // red
                data[i][j].red   = 1.0f;
                data[i][j].green = 0.0f;
                data[i][j].blue  = 0.0f;
                break;
            case 2: // green
                data[i][j].red   = 0.0f;
                data[i][j].green = 1.0f;
                data[i][j].blue  = 0.0f;
                break;
            case 3: // blue
                data[i][j].red   = 0.0f;
                data[i][j].green = 0.0f;
                data[i][j].blue  = 1.0f;
                break;
            case 4: // white
                data[i][j].red   = 1.0f;
                data[i][j].green = 1.0f;
                data[i][j].blue  = 1.0f;
                break;
            case 5: // random
                data[i][j].red   = (float(rand()) / float((RAND_MAX)));
                data[i][j].green = (float(rand()) / float((RAND_MAX)));
                data[i][j].blue  = (float(rand()) / float((RAND_MAX)));
                break;

            }
        }
}

void Matriz10q::Identidade()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (i == j)
            {
                data[i][j].red   = 1.0f, 0.0f, 0.0f;
                data[i][j].green = 0.0f, 1.0f, 0.0f;
                data[i][j].blue  = 0.0f, 0.0f, 1.0f;
            }
                

            else
            {
                data[i][j].red   = 0.0f, 0.0f, 0.0f;
                data[i][j].green = 0.0f, 0.0f, 0.0f;
                data[i][j].blue  = 0.0f, 0.0f, 0.0f;
            }

}
void Matriz10q::Transposta()
{
    Matriz10q temp;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            temp.data[j][i] = data[i][j];
    
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            data[i][j] = temp.data[i][j];
            

}
void Matriz10q::Soma(Matriz10q M)
{

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            data[i][j].red   = data[i][j].red   + M.data[i][j].red;
            data[i][j].green = data[i][j].green + M.data[i][j].green;
            data[i][j].blue  = data[i][j].blue  + M.data[i][j].blue;

        }
}

Matriz10q Matriz10q::Soma2Matrizes(Matriz10q A, Matriz10q B)
{
    Matriz10q C;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            C.data[i][j].red   = A.data[i][j].red   + B.data[i][j].red;
            C.data[i][j].green = A.data[i][j].green + B.data[i][j].green;
            C.data[i][j].blue  = A.data[i][j].blue  + B.data[i][j].blue;

        }

    return C;
}
void Matriz10q::Subtrai(Matriz10q M)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            data[i][j].red   = data[i][j].red   - M.data[i][j].red;
            data[i][j].green = data[i][j].green - M.data[i][j].green;
            data[i][j].blue  = data[i][j].blue  - M.data[i][j].blue;

        }
}
void Matriz10q::Multiplica(Matriz10q M)
{
    float tempRed[9][9] = {  {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0} };

    float tempGreen[9][9] = { {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0} };

    float tempBlue[9][9] = { {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0} };


    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            for (int k = 0; k < 9; k++)
            {
                tempRed[i][j]   += data[i][k].red   * M.data[k][j].red;
                tempGreen[i][j] += data[i][k].green * M.data[k][j].green;
                tempBlue[i][j]  += data[i][k].blue  * M.data[k][j].blue;

            }
                
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            data[i][j].red   = tempRed[i][j];
            data[i][j].green = tempGreen[i][j];
            data[i][j].blue  = tempBlue[i][j];

        }
}

void Matriz10q::MultiplicaEscalar(float k) 
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            data[i][j].red   = k * data[i][j].red;
            data[i][j].green = k * data[i][j].green;
            data[i][j].blue  = k * data[i][j].blue;
        }
}

Matriz10q::~Matriz10q()
{

}
