## Projeto de Computação Gráfica: Projeção Ortogonal e Interação

Este projeto em C++ utiliza **OpenGL (via GLUT/GLEW)** para demonstrar a **Projeção Ortogonal** em um ambiente 3D, permitindo ao usuário manipular a cena através de rotação e zoom. O código é apresentado em três variações (0, 1 e 2), sendo o arquivo principal a base para o aprendizado de interações.

### 🎯 Objetivo

Visualizar um conjunto de primitivas 3D (Cubo e Esferas) usando a **Projeção Ortogonal** e implementar controles de usuário via teclado (setas) e mouse (botões) para rotacionar o modelo e aplicar zoom.

### 🧱 Estrutura do Código

O projeto é dividido em três arquivos principais, que utilizam o mesmo *setup* de cena e interação:

| Arquivo | Descrição | Primitivas Desenhadas |
| :--- | :--- | :--- |
| **`main-ortho0.cpp`** | Versão inicial da demonstração | Um Cubo, quatro Esferas e o Sistema de Eixos XYZ. |
| **`main-ortho1.cpp`** | (Variação de `main-ortho0.cpp`) | Mesmas primitivas (Cubo e Esferas) e o Sistema de Eixos XYZ. |
| **`main-ortho2.cpp`** | (Variação de `main-ortho0.cpp`) | Mesmas primitivas (Cubo e Esferas) e o Sistema de Eixos XYZ. |

### 💡 Projeção Ortogonal (`reshape`)

A Projeção Ortogonal é configurada na função `reshape`, que é chamada sempre que a janela é redimensionada.

* **Volume de Visualização:** O volume de visualização é definido pelo comando `glOrtho()`. Este tipo de projeção não simula profundidade, mantendo as dimensões e o paralelismo das linhas do objeto, independentemente da distância.
* **Configuração:** O volume é ajustado dinamicamente para manter a proporção da tela (`w/h`), centralizando o sistema de coordenadas em 0.

### 💻 Interação e Controles

A interação permite ao usuário explorar o modelo 3D estático, que é desenhado usando o modo de renderização `GL_LINE_STRIP` ou `GL_QUADS` (dependendo da primitiva).

| Ação | Tecla/Mouse | Função |
| :--- | :--- | :--- |
| **Rotação da Cena (Eixo X)** | Setas UP/DOWN | Altera o ângulo de rotação (`anglex`). |
| **Rotação da Cena (Eixo Y)** | Setas LEFT/RIGHT | Altera o ângulo de rotação (`angley`). |
| **Zoom In** | Botão Esquerdo do Mouse | Aumenta o fator de escala (`zoom`). |
| **Zoom Out** | Botão Direito do Mouse | Diminui o fator de escala (`zoom`). |

#### Sistema de Eixos
O sistema de eixos XYZ é desenhado para fornecer um referencial espacial:
* **Eixo X:** Vermelho
* **Eixo Y:** Verde
* **Eixo Z:** Azul.

---