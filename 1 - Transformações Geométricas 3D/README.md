## Projeto de Computação Gráfica: Transformações Geométricas 3D

Este projeto em C++ utiliza a biblioteca **OpenGL (via GLUT e GLEW)** para demonstrar e aplicar **transformações geométricas 3D** (Translação, Escala e Rotação) a um objeto customizado. O foco está na implementação manual das operações matriciais em coordenadas homogêneas.

### 🎯 Objetivo

Visualizar um objeto 3D definido por coordenadas e aplicar uma sequência de transformações (Escala) em relação a um ponto de referência (centro do objeto), utilizando classes `Matriz4q` e `Objeto` para gerenciar as operações matemáticas.

### 🧱 Estrutura do Código

O projeto é dividido em um arquivo principal (`main.cpp`) e três arquivos de cabeçalho/implementação para as classes de matriz e objeto.

| Arquivo | Descrição | Foco |
| :--- | :--- | :--- |
| **`main.cpp`** | Ponto de entrada do OpenGL/GLUT. Configura a projeção, o observador, o *viewport*, e contém o laço principal (`render()`) onde as transformações são aplicadas e o objeto é desenhado. | **Inicialização, Lógica de Transformação e Desenho** |
| **`Matriz4q.h`/`Matriz4q.cpp`** | Define e implementa a classe para matrizes $4 \times 4$. Contém métodos para as transformações básicas (Translação, Escala, Rotação) e operações (Identidade, Soma, Multiplicação). | **Implementação de Álgebra Linear Homogênea** |
| **`Objeto.h`/`Objeto.cpp`** | Define e implementa a classe `Objeto`. Armazena o conjunto de vértices e possui o método `Transforma()` para multiplicar o objeto por uma matriz de transformação. | **Modelo de Objeto 3D e Aplicação de Matrizes** |
| **`CG_Projection_01.pde`** | (Código em Processing) Contém implementações análogas de multiplicação de matrizes/vetores, ilustrando o conceito de projeção/transformação de visualização. | **Referência Conceitual de Multiplicação Matriz/Vetor** |

### 📐 Implementação das Transformações

A principal lógica de transformação ocorre em `main.cpp` dentro da função `render()`, onde as operações se acumulam a cada *frame* (o que resulta em uma animação contínua de redução).

#### Coordenadas Homogêneas
* O objeto `Ob1` é definido por 13 vértices em coordenadas homogêneas (vetores de 4 componentes: $[x, y, z, 1]$).
* As matrizes de transformação $4 \times 4$ são criadas e aplicadas sequencialmente.

#### Transformação Composta (Escala Relativa ao Centro)
O código aplica uma **escala de redução** (`0.5f`) relativa ao centro do objeto (que é (200, 200, 10)) através da seguinte sequência:

1.  **`M_T1.Translacao(-200.0f, -200.0f, 0.0f);`**: Translada o objeto para a origem.
2.  **`M_T2.Escala(0.5f, 0.5f, 0.5f);`**: Aplica a escala.
3.  **`M_T3.Translacao(200.0f, 200.0f, 0.0f);`**: Translada o objeto de volta ao seu centro de origem.
4.  **Multiplicação:** As matrizes são acumuladas na ordem $M_{T1} \times M_{T2} \times M_{T3}$.
5.  **Aplicação:** `Ob1.Transforma(M_T1);` aplica a matriz composta aos vértices do objeto.

### 💻 Interação e Visualização

O programa configura uma **projeção perspectiva** e inclui controles para manipulação da cena:

| Ação | Tecla/Mouse | Função |
| :--- | :--- | :--- |
| **Rotação da Cena** | Setas (UP/DOWN/LEFT/RIGHT) | Rotação sobre os eixos X e Y. |
| **Zoom** | Botão Esquerdo (in) / Direito (out) do Mouse | Altera o ângulo de visão (`angleV`) da projeção perspectiva. |
| **Movimento do Observador** | Teclas A, S, W, Z | Reposiciona o observador (`obsX`, `obsY`). |
| **Reset** | Tecla R | Restaura a projeção e a posição do observador para os valores iniciais. |

---