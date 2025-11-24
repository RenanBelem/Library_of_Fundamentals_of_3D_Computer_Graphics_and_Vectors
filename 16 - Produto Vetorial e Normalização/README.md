## Projeto de Computação Gráfica: Produto Vetorial e Normalização (C++ / OpenGL)

Este projeto em C++ com **OpenGL (via GLUT/GLEW)** demonstra o cálculo e a visualização de operações fundamentais da álgebra vetorial no espaço 3D, com foco no **Produto Vetorial** e na **Normalização de Vetores**.

### 🎯 Objetivo

Modelar e desenhar **Pontos** e **Vetores** em um *sandbox* 3D para:
1.  Gerar vetores de aresta a partir de três pontos que definem um plano.
2.  Calcular o **Vetor Normal** (vetor perpendicular ao plano) usando o **Produto Vetorial**.
3.  **Normalizar** o vetor resultante (Normal) para que ele tenha magnitude unitária.

### 🧱 Estrutura do Código

O projeto é composto por um arquivo principal (`main.cpp`) que integra a lógica de cena com as classes `Ponto` e `Vetor`:

| Arquivo | Classe | Foco |
| :--- | :--- | :--- |
| **`main.cpp`** | N/A | Contém a lógica de inicialização do OpenGL, a definição dos três pontos, o cálculo dos vetores (subtração), o **Produto Vetorial**, e a **Normalização**. |
| **`ClasseVetor.h`/`.cpp`** | `Vetor` | Define um vetor 3D (`xcomp`, `ycomp`, `zcomp`). Implementa o **`ProdutoVetorial`** e o método **`Normalizar`** (divide componentes pela Magnitude). Também possui métodos para Soma, Subtração e Produto Escalar. |
| **`ClassePonto.h`/`.cpp`** | `Ponto` | Define um ponto 3D ($x, y, z$). Utilizado para desenhar os vértices e calcular os vetores de aresta. |

### 💡 Lógica Central: Cálculo da Normal

O `main.cpp` estabelece a geometria básica do plano e aplica as operações vetoriais para encontrar o vetor Normal ($\vec{v}_5$):

1.  **Definição dos Vértices:** Três pontos (`A`, `B`, `C`) definem um triângulo no espaço 3D.
2.  **Vetor Aresta:** Os vetores $\vec{v}_1 = \vec{B} - \vec{A}$ e $\vec{v}_2 = \vec{C} - \vec{B}$ são formados.
3.  **Produto Vetorial:** A função `v5.ProdutoVetorial(v1, v2)` é chamada para calcular o vetor perpendicular $\vec{v}_5$.
4.  **Normalização:** O método `v5.Normalizar()` é chamado para transformar o vetor resultante em um **vetor unitário** (magnitude = 1), essencial para a iluminação em Computação Gráfica.

### 💻 Interação e Visualização

A cena exibe os vetores e os pontos em uma **Projeção Ortogonal** (implícita pelo *sandbox* do código, ou seja, `nRange = 200`) e permite a manipulação interativa do ponto de vista.

| Ação | Tecla/Mouse | Função |
| :--- | :--- | :--- |
| **Rotação da Cena (X, Y, Z)** | Setas UP/DOWN/LEFT/RIGHT / PgUp/PgDn | Permite rotacionar a cena para inspecionar os vetores e a Normal. |
| **Zoom** | Botões Esquerdo/Direito do Mouse | Altera o fator de escala (`zoom`). |