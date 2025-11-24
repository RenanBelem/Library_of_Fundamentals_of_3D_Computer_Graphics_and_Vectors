## Projeto de Computação Gráfica: Produto Vetorial e Normalização (C++ / OpenGL)

Este projeto em C++ com **OpenGL (via GLUT/GLEW)** demonstra o cálculo e a visualização do **Produto Vetorial** e a **Normalização de Vetores** no espaço 3D. A cena exibe três pontos definidos e os vetores formados por eles, juntamente com o vetor normal à superfície que eles definem.

### 🎯 Objetivo

1.  Modelar e desenhar **Pontos** e **Vetores** em 3D.
2.  Calcular o **Produto Vetorial** entre dois vetores para encontrar o vetor **Normal** à superfície.
3.  **Normalizar** o vetor resultante (Normal) para que ele tenha magnitude unitária.

### 🧱 Estrutura do Código

O projeto é composto por um arquivo principal (`main.cpp`) e classes de modelo para `Ponto` e `Vetor`:

| Arquivo | Classe | Foco |
| :--- | :--- | :--- |
| **`main.cpp`** | N/A | Lógica de cálculo (Produto Vetorial e Normalização) e renderização da cena. |
| **`ClassePonto.h`/`.cpp`** | `Ponto` | Define um ponto 3D ($x, y, z$) e implementa o método `Desenha()` (renderiza como uma esfera). |
| **`ClasseVetor.h`/`.cpp`** | `Vetor` | Define um vetor 3D ($xcomp, ycomp, zcomp$) e implementa operações essenciais como **`ProdutoVetorial`** e **`Normalizar`**. |

### 💡 Lógica Central (`main.cpp`)

O código demonstra a definição do plano e a obtenção de sua normal (vetor perpendicular).

#### 1. Definição de Pontos e Vetores
Três pontos (`A`, `B`, `C`) são definidos para formar um plano.

* **Ponto A:** (0, 0, 100)
* **Ponto B:** (100, 0, 0)
* **Ponto C:** (0, 100, 0)

Três vetores (`v1`, `v2`, `v3`) são criados a partir das subtrações dos pontos, definindo os lados de um triângulo:

* $\vec{v}_1 = \vec{B} - \vec{A}$
* $\vec{v}_2 = \vec{C} - \vec{B}$
* $\vec{v}_3 = \vec{A} - \vec{C}$

#### 2. Cálculo do Vetor Normal
O vetor normal ($\vec{v}_5$) ao plano (definido por $\vec{v}_1$ e $\vec{v}_2$) é calculado através do **Produto Vetorial**:

1.  **Produto Vetorial:** `v5 = v5.ProdutoVetorial(v1, v2);`
    * Esta operação resulta em um vetor perpendicular ao plano que contém $\vec{v}_1$ e $\vec{v}_2$.
2.  **Normalização:** `v5.Normalizar();`
    * O vetor $\vec{v}_5$ é escalado para ter uma **Magnitude Unitária** (comprimento igual a 1).
3.  **Escala para Visualização:** `v5.MultEscalar(50.0);`
    * O vetor normalizado é escalado por 50.0 para ser visível na cena.

#### 3. Desenho na Cena
* Os vetores $\vec{v}_1$, $\vec{v}_2$ e $\vec{v}_3$ são desenhados a partir de suas respectivas origens (0, 0, 100) e (100, 0, 0).
* O vetor normal ($\vec{v}_5$) é desenhado a partir do **centroide** do triângulo formado pelos pontos $A, B, C$: `(A.x + B.x + C.x)/3, ...`.

### 🛠 Implementação Vetorial (`ClasseVetor.cpp`)

O método `ProdutoVetorial(Vetor v1, Vetor v2)` na classe `Vetor` implementa a fórmula do produto vetorial:

$$\vec{v}_r = (v_{1y}v_{2z} - v_{1z}v_{2y}, \quad v_{1z}v_{2x} - v_{1x}v_{2z}, \quad v_{1x}v_{2y} - v_{1y}v_{2x})$$

O método `Normalizar()` divide cada componente pela `Magnitude()` do vetor.

### 💻 Interação e Visualização

A cena é renderizada com projeção ortogonal e inclui um *grid* auxiliar.

| Ação | Tecla/Mouse | Efeito |
| :--- | :--- | :--- |
| **Rotação da Cena** | Setas (UP/DOWN/LEFT/RIGHT) / PgUp/PgDn | Rotaciona a perspectiva para visualizar os vetores e a normal. |
| **Zoom** | Botões Esquerdo/Direito do Mouse | Altera o fator de escala (`zoom`) da cena. |