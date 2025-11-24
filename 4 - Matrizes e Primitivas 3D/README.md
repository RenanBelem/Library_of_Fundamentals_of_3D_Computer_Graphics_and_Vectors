## Projeto de Computação Gráfica: Matrizes e Primitivas 3D

Este projeto em C++ com **OpenGL (via GLUT/GLEW)** foca na implementação de estruturas de dados matriciais e sua visualização. O código define duas classes de matriz (`Matriz4q` e `Matriz10q`) e um *main loop* que demonstra operações básicas de álgebra linear no console e a renderização de uma grade de cubos coloridos (`Matriz10q`) na tela.

### 🎯 Objetivo

1.  Implementar as operações fundamentais de **álgebra linear** (soma, multiplicação, transposta, identidade) para matrizes $4 \times 4$ (coordenadas homogêneas).
2.  Criar uma estrutura de matriz $10 \times 10$ que armazena informações de cor (RGB) e visualizá-la como uma grade de cubos coloridos 3D.

### 🧱 Estrutura do Código

O projeto é baseado nas classes de matriz e nos arquivos principais de renderização do OpenGL:

| Arquivo | Classe | Foco |
| :--- | :--- | :--- |
| **`Matriz4q.h` / `Matriz4q.cpp`** | `Matriz4q` | Define e implementa uma matriz $4 \times 4$ para operações de Transformação de Visualização (Translação, Escala, Rotação) e operações básicas de álgebra linear. **Foco em coordenadas homogêneas**. |
| **`Matriz10q.h` / `Matriz10q.cpp`** | `Matriz10q` | Define e implementa uma matriz $10 \times 10$ onde cada elemento é uma estrutura de cor (`cor`) RGB. Contém o método `Desenha()` para renderizar a matriz como cubos 3D. |
| **`main.cpp`** | N/A | Contém o *main loop*, inicialização do OpenGL e **demonstrações das operações da `Matriz4q` no console**. |
| **`Matriz.cpp`** | N/A | Um arquivo que parece ser uma cópia ou continuação de `main.cpp`, demonstrando a visualização de múltiplas instâncias de `Matriz10q` na cena OpenGL. |

---

### 1. Classe `Matriz4q` (Matrizes 4x4)

Esta classe lida com as operações necessárias para a Computação Gráfica 3D:

#### Operações de Álgebra Linear
* `Identidade()`: Define a matriz como uma matriz identidade.
* `Transposta()`: Transpõe a matriz.
* `Soma(Matriz4q M)` / `Subtrai(Matriz4q M)`: Adição e Subtração.
* `Multiplica(Matriz4q M)`: Multiplicação de matrizes $4 \times 4$.
* `MultiplicaEscalar(float k)`: Multiplica todos os elementos por um escalar.

#### Matrizes de Transformação (Coordenadas Homogêneas)
* `Translacao(float dx, float dy, float dz)`: Preenche a matriz com os valores de translação.
* `Escala(float sx, float sy, float sz)`: Preenche a matriz com os valores de escala.
* `RotacaoX/Y/Z(float angulo)`: Preenche a matriz com os valores de rotação (em X, Y ou Z).

### 2. Classe `Matriz10q` (Visualização 3D)

Esta classe é usada primariamente para visualização de dados coloridos:

* **Estrutura de Cor:** Utiliza uma `struct cor { float red, green, blue; }` para armazenar a cor de cada célula.
* **Inicialização Colorida:** O construtor `Matriz10q(int CC)` permite inicializar a matriz com cores fixas (vermelho, verde, azul, branco) ou cores aleatórias (`case 5: random`).
* **Visualização (`Desenha`):** Percorre a matriz $10 \times 10$ (células de $9 \times 9$ na prática) e desenha um `glutSolidCube(18.0f)` em cada posição, usando a cor armazenada na célula.

### 3. Demonstração de Operações (`main.cpp` e `Matriz.cpp`)

A seção `main()` e a função `render()` demonstram o uso das classes:

* **Teste de Álgebra Linear (Console):** O `main.cpp` inicializa `M_A` (zero), `M_B` (com dados iniciais) e executa uma sequência de operações (Transposta, Identidade, Multiplicação, Soma, Escala) e imprime o resultado no console.
* **Visualização na Cena:** O `Matriz.cpp` cria múltiplas instâncias de `Matriz10q` com cores diferentes e as renderiza em posições distintas na cena 3D.