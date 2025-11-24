## Animação 3D com Vetores: Simulação de Física (C++ / OpenGL)

Este projeto demonstra a aplicação de conceitos de **vetores** e **física** (movimento e gravidade) em um ambiente 3D, utilizando a biblioteca **OpenGL (via GLUT/GLEW)**. Um objeto (cubo) se move na cena sob a influência de velocidade e aceleração (gravidade).

### 🎯 Objetivo

Simular o movimento de um objeto em 3D, aplicando a integração vetorial de **posição**, **velocidade** e **gravidade**, e gerenciar colisões básicas com os limites do volume de visualização.

### 🧱 Estrutura do Código

O projeto é composto pelos seguintes arquivos:

| Arquivo | Descrição | Foco |
| :--- | :--- | :--- |
| **`main_2.cpp`** | O arquivo principal. Contém a lógica de inicialização do OpenGL, a função de renderização (`render`), e a função de atualização (`update`) que implementa a simulação física. | **Simulação Física e Lógica da Cena** |
| **`ClasseVetor.cpp`** | Define a classe `Vetor` (ou `ClasseVetor_2.cpp` no segundo arquivo) com componentes $x, y, z$. Inclui métodos essenciais para manipulação vetorial. | **Implementação da Classe Vetor** |

### 📐 Classe `Vetor` (ou `ClasseVetor_2.cpp`)

A classe é a espinha dorsal da simulação, permitindo a manipulação de grandezas vetoriais:

* **Atributos:** `xcomp`, `ycomp`, `zcomp` (componentes do vetor).
* **Operações:**
    * `SomaVetor(tVetor)` / `Soma2Vetores(v1, v2)`: Adição vetorial.
    * `MultEscalar(k)`: Multiplicação por um escalar.
    * `Magnitude()`: Cálculo do comprimento do vetor.
    * `Desenha(xpos, ypos, zpos)`: Desenha o vetor como uma linha 3D com uma esfera na ponta, a partir de uma posição inicial.

### 💡 Lógica da Simulação (`main_2.cpp`)

A simulação é controlada por três vetores globais e a função `update(value)`:

1.  **Vetores de Estado:**
    * `posicao`: Posição atual do objeto (começa em (0, 0, 0)).
    * `velocidade`: Velocidade atual do objeto (começa em (1.5, 2.1, 1.0)).
    * `gravidade`: Aceleração constante aplicada no eixo Y (vertical), simulando a gravidade (0.0, -0.2, 0.0).

2.  **Ciclo de Atualização (`update`)**: Chamada a cada 25ms (`glutTimerFunc(25, update, 0)`).
    * **Atualização de Posição:** A nova posição é calculada integrando a velocidade: `posicao.SomaVetor(velocidade);`.
    * **Atualização de Velocidade (Aceleração):** A gravidade é adicionada à velocidade: `velocidade.SomaVetor(gravidade);`.
    * **Colisão:** Se o objeto atinge os limites do volume de visualização (`nRange`), o componente de velocidade correspondente é invertido (`* -1`).
    * **Colisão com o "Chão" (Eixo Y):** Na colisão com o limite inferior de Y, a velocidade é reduzida (`* -0.95`), simulando perda de energia.

### 💻 Interação e Visualização

A cena é renderizada com um sistema de coordenadas cartesiano 3D (eixos X, Y, Z) e um *grid* auxiliar. Um cubo colorido é desenhado na posição do vetor `posicao`.

| Ação | Tecla/Mouse | Efeito |
| :--- | :--- | :--- |
| **Rotação da Cena** | Setas (UP/DOWN/LEFT/RIGHT) / PgUp/PgDn | Rotaciona a perspectiva para visualizar o movimento do objeto no espaço 3D. |
| **Zoom** | Botões Esquerdo/Direito do Mouse | Altera o fator de escala (`zoom`) da cena. |
| **Objeto Animado** | N/A (Automático) | O cubo se move em trajetória balística sob a influência da `velocidade` e `gravidade`. |

---