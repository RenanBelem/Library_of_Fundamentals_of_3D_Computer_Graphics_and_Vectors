## Projeto de Computação Gráfica: Projeção Ortogonal e Desenho de Cubo (C++ / OpenGL)

Este projeto em C++ utiliza a biblioteca **OpenGL (via GLUT/GLEW)** para demonstrar a renderização de uma primitiva geométrica complexa (o cubo) sob **Projeção Ortogonal**, e implementa controles de interação para manipulação da cena.

### 🎯 Objetivo

Visualizar um **cubo 3D** desenhado a partir de uma tira de triângulos (`GL_TRIANGLE_STRIP`) e permitir a manipulação interativa do ângulo de visão e do zoom na cena, utilizando um volume de visualização ortogonal fixo.

### 🧱 Estrutura do Código (`Ex4 cds3d.cpp`)

O código é uma aplicação OpenGL/GLUT standalone:

* **`cubo(float a)`:** Função central que desenha um cubo. O cubo é modelado usando uma única **tira de triângulos (`GL_TRIANGLE_STRIP`)**. Este método otimiza o desenho, pois cada vértice cria novos triângulos com os dois vértices anteriores.
* **`initGL()`:** Configura o ambiente 3D: limpa a cor de fundo, habilita o **teste de profundidade (`glEnable(GL_DEPTH_TEST)`)** e define o modelo de sombreamento como suave (`GL_SMOOTH`).
* **`reshape()`:** Define a **Projeção Ortogonal** (`glOrtho`) com um alcance fixo (`nRange = 200`), garantindo que o objeto não sofra distorção de perspectiva.
* **`render()`:** É a função de desenho que aplica as rotações interativas (`glRotatef`) e chama a função `cubo(50)` para desenhar a primitiva.

### 💻 Interação e Controles

O programa permite ao usuário manipular a cena para inspecionar o cubo de todos os ângulos:

| Ação | Tecla/Mouse | Efeito |
| :--- | :--- | :--- |
| **Rotação da Cena (X e Y)** | Setas UP/DOWN/LEFT/RIGHT | Rotação sobre os eixos X e Y. |
| **Rotação da Cena (Z)** | Teclas PgUp / PgDn | Rotação sobre o eixo Z. |
| **Zoom In** | Botão Esquerdo do Mouse | Aumenta o fator de escala (`zoom`). |
| **Zoom Out** | Botão Direito do Mouse | Diminui o fator de escala (`zoom`). |

---