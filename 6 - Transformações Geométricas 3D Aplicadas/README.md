## Projeto de Computação Gráfica: Transformações Geométricas 3D Aplicadas

Este projeto em C++ usa **OpenGL (via GLUT/GLEW)** para aplicar transformações geométricas 3D (Translação, Escala e Rotação) a um objeto customizado, demonstrando o poder das coordenadas homogêneas e operações matriciais para manipular a geometria de cena.

### 🎯 Objetivo

Visualizar um objeto 3D definido por coordenadas e aplicar uma sequência de **transformações geométricas 3D** (Translação, Escala, Rotação) de forma interativa. O foco está na implementação manual e na aplicação correta das operações matriciais em coordenadas homogêneas.

### 🧱 Estrutura do Código

O projeto é estruturado em torno de três classes principais que modelam as matrizes de transformação e o objeto 3D, além de um *main loop* para renderização:

| Arquivo | Classe | Foco |
| :--- | :--- | :--- |
| **`main.cpp`** | N/A | Ponto de entrada do OpenGL/GLUT. Configura a projeção, o observador, o *viewport*, e contém o laço principal (`render()`) onde as transformações são aplicadas e o objeto é desenhado. |
| **`Matriz4q.h`/`Matriz4q.cpp`** | `Matriz4q` | Define e implementa uma matriz $4 \times 4$. Contém métodos para as transformações básicas (**Translação, Escala, Rotação**) e operações de álgebra linear (**Soma, Multiplicação**) necessárias para coordenadas homogêneas. |
| **`Objeto.h`/`Objeto.cpp`** | `Objeto` | Define o modelo geométrico (lista de vértices) e a topologia (faces/bordas). Contém o método `Transforma()` que multiplica os vértices do objeto pela matriz de transformação acumulada. |
| **`main-transf-select.cpp`** | N/A | Contém o código que demonstra a **seleção interativa de transformações** (aplicação de translação, escala ou rotação) e a animação do objeto em $M_{VISUAL}$. |

### 📐 Implementação das Transformações

As transformações são construídas e aplicadas em coordenadas homogêneas (matrizes $4 \times 4$).

#### Classe `Matriz4q`
Esta classe implementa as operações fundamentais exigidas pela Computação Gráfica:

* `Identidade()`: Cria a matriz identidade.
* `Translacao(dx, dy, dz)`: Cria a matriz de translação.
* `Escala(sx, sy, sz)`: Cria a matriz de escala.
* `RotacaoX/Y/Z(angulo)`: Cria as matrizes de rotação.
* `Multiplica(Matriz4q M)`: Realiza o produto entre matrizes.

#### Transformação Composta
No arquivo principal (`main.cpp`), as transformações são **acumuladas** e aplicadas ao objeto:

1.  **Matriz Acumulada (`M_T`)**: Uma matriz identidade é inicializada.
2.  **Translação/Escala/Rotação**: As matrizes individuais de transformação são multiplicadas e o resultado é armazenado em `M_T`. A ordem de multiplicação é crucial.
3.  **Aplicação**: O objeto é desenhado após a aplicação da matriz acumulada: `Ob1.Transforma(M_T);`.

### 💻 Interação e Visualização (`main.cpp` / `main-transf-select.cpp`)

A cena é renderizada com um sistema de coordenadas 3D auxiliar (eixos X, Y, Z) e a projeção configurada para simular profundidade.

| Ação | Tecla/Mouse | Função |
| :--- | :--- | :--- |
| **Transformação (Rotação/Escala)** | Teclas A, S, W, Z | Permitem modificar os parâmetros da transformação aplicada. Por exemplo, 'A' e 'S' podem aumentar/diminuir o ângulo de rotação. |
| **Seleção de Transformação** | Teclas 1, 2, 3 | Alterna entre Translação, Escala e Rotação para que as teclas A, S, W, Z controlem o parâmetro ativo. |
| **Reset** | Tecla R | Restaura a transformação acumulada para a Matriz Identidade. |
| **Rotação/Zoom da Câmera** | Setas/Mouse | Permite ao usuário alterar o ponto de vista (câmera) para melhor inspeção do objeto transformado. |

---