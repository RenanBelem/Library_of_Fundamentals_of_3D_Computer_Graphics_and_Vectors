## Projeto de Computação Gráfica: Matrizes de Transformação 3D (Refatorado)

Este projeto em C++ com **OpenGL (via GLUT/GLEW)** demonstra a manipulação de matrizes $4 \times 4$ em **coordenadas homogêneas**, que são essenciais para aplicar **transformações geométricas 3D** (Translação, Escala, Rotação) a um objeto. O projeto usa classes modulares para gerenciar a matemática vetorial e matricial.

### 🎯 Objetivo

Modelar a estrutura de uma **matriz $4 \times 4$** (`Matriz4q`) e implementar as operações fundamentais (multiplicação, translação, escala, rotação) que formam a base de qualquer motor de visualização 3D.

### 🧱 Estrutura do Código

O projeto é baseado em três arquivos centrais:

| Arquivo | Classe | Foco |
| :--- | :--- | :--- |
| **`Matriz4q.h`** | `Matriz4q` | Define a estrutura da matriz $4 \times 4$ (composta por um *array* `data[4][4]`) e declara todos os métodos de operação (Soma, Multiplicação, Translação, Escala, Rotação). |
| **`Matriz4q.cpp`** | `Matriz4q` | Implementa a lógica de cada operação declarada no cabeçalho. Destaca-se a implementação da **multiplicação de matrizes** $4 \times 4$ e a criação das matrizes de **translação**, **escala** e **rotação**. |
| **`main.cpp`** | N/A | Arquivo principal que testa as funcionalidades da classe `Matriz4q` no console. Ele inicializa e manipula matrizes para demonstrar as operações de álgebra linear e transformações. |

### 💡 Implementação das Operações em `Matriz4q`

A classe `Matriz4q` é o núcleo matemático do projeto. O uso de matrizes $4 \times 4$ permite que as transformações (Translação, Escala e Rotação) sejam tratadas de forma unificada (coordenadas homogêneas).

#### Operações Fundamentais
* **`Multiplica(Matriz4q M2)`:** Implementa a multiplicação de matrizes. Esta é a operação mais crucial, pois permite a **composição de transformações** (encadeamento de rotação, escala e translação).
* **`Transposta()`:** Inverte as linhas e colunas da matriz.
* **`Soma(Matriz4q M)` / `Subtrai(Matriz4q M)`:** Implementam as operações de soma e subtração elemento a elemento.

#### Matrizes de Transformação (Coordenadas Homogêneas)
As funções de transformação constroem a matriz de forma que, quando multiplicada por um vetor de coordenada $[x, y, z, 1]$, produza o novo vetor transformado:

* **`Translacao(float dx, float dy, float dz)`:** Preenche a matriz para aplicar o deslocamento $(dx, dy, dz)$.
* **`Escala(float sx, float sy, float sz)`:** Preenche a matriz para aplicar o fator de escala $(sx, sy, sz)$.
* **`RotacaoX/Y/Z(float angulo)`:** Preenche a matriz com os valores trigonométricos (seno e cosseno) para rotacionar o objeto em torno de um eixo específico.

### 💻 Demonstração (`main.cpp`)

O arquivo principal demonstra a versatilidade da classe `Matriz4q` ao inicializar e manipular várias matrizes (`M_A`, `M_B`, `M_C`):

1.  **Inicialização e Cópia:** `M_A` é criada, e `M_B` é inicializada com um conjunto de dados predefinidos (`float data1[4][4]`).
2.  **Operações em Sequência:** O código executa e imprime no console os resultados de:
    * Matriz B Transposta.
    * Matriz A como Identidade.
    * Multiplicação de `M_B` por `M_A`.
    * Soma de `M_B` com `M_A`.
    * Multiplicação escalar (`* 2.0f`) de `M_B`.
3.  **Transformação:** `M_B` é definida como uma matriz de **Escala Uniforme** de 50% (`M_B.Escala(0.5f, 0.5f, 0.5f)`).