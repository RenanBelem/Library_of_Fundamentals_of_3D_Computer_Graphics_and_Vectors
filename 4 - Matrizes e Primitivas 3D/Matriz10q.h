class Matriz10q
{
public:
    typedef struct cor {
        float red;
        float green;
        float blue;

    };
    cor data[10][10];
public:
    Matriz10q();
    Matriz10q(int CC);
    void Desenha(float xpos, float ypos, float zpos);
    void Identidade();
    void Transposta();
    void Soma(Matriz10q M);
    Matriz10q Soma2Matrizes(Matriz10q, Matriz10q);
    void Subtrai(Matriz10q M);
    void Multiplica(Matriz10q M);
    void MultiplicaEscalar(float k);
    ~Matriz10q();
};
