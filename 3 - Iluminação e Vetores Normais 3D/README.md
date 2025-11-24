## Projeto de Computação Gráfica: Iluminação e Normais 3D

Este projeto em C++ usa **OpenGL (via GLUT/GLEW)** para explorar o conceito de **Iluminação** e o cálculo dos **Vetores Normais** em superfícies 3D (Triângulos, Tetraedros, Discos e Cubos).

### 🎯 Objetivo

1.  Demonstrar a diferença visual entre objetos renderizados **com** e **sem** o cálculo explícito dos vetores normais, sob a influência de uma fonte de luz.
2.  Implementar o cálculo manual do vetor normal (Produto Vetorial) para faces de triângulos.
3.  Implementar e desenhar diferentes primitivas 3D, como um Tetraedro, Disco e Cubo, com suas respectivas normais.

### 🧱 Estrutura do Código

O projeto principal (`main.cpp` e `3-main-triangulos-ilum-normais.cpp`) depende de várias classes de geometria:

| Arquivo | Descrição | Foco |
| :--- | :--- | :--- |
| **`main.cpp`** | Arquivo principal que demonstra a iluminação de um **Tetraedro** (`TetraHedro` class) com um sistema de coordenadas e interações. Inclui o *setup* da luz ambiente, difusa e especular. | **Iluminação, Material e Primitiva Customizada** |
| **`3-main-triangulos-ilum-normais.cpp`** | Demonstração clara da diferença entre um Tetraedro desenhado **sem** normais (`tetraHedro1`) e **com** normais calculadas (`tetraHedro2`). | **Comparação de Normais Calculadas vs. Ausentes** |
| **`Triangle.h`/`Triangle.cpp`** | **(Implícito)** Classe que calcula o vetor normal de uma face triangular. | **Cálculo do Vetor Normal** |
| **`TetraHedro.h`/`TetraHedro.cpp`** | **(Implícito)** Define e desenha um tetraedro a partir de triângulos, aplicando as normais. | **Modelo de Tetraedro** |
| **`Disk.h`/`Disk.cpp`** | Classe para desenhar um **Disco** 2D (círculo preenchido) no plano XY. O vetor normal é fixo (0, 0, 1) e desenhado no centro. | **Primitiva: Disco** |
| **`Cone.h`/`Cone.cpp`** | Classe para desenhar a base de um **Cone** (como um disco). | **Primitiva: Cone (Base)** |
| **`Cube.h`/`Cube.cpp`** | Classe que define um **Cubo** usando 12 triângulos (6 faces x 2 triângulos) e desenha os vetores normais para cada face. | **Primitiva: Cubo e Desenho das Normais** |

### 💡 Conceitos Chave

#### Cálculo de Normal (`3-main-triangulos-ilum-normais.cpp`)

A função `calcNormal(v[3][3], out[3])` calcula o vetor normal $\vec{N}$ de uma face triangular através do **Produto Vetorial** $(\vec{v}_1 \times \vec{v}_2)$ entre dois vetores de aresta $\vec{v}_1$ e $\vec{v}_2$ da face:

1.  Calcula os vetores $\vec{v}_1$ e $\vec{v}_2$ subtraindo os vértices.
2.  Aplica a fórmula do produto vetorial para obter a normal.
3.  Normaliza o vetor resultante (`normaliza(out)`) para torná-lo unitário.
4.  O vetor $\vec{N}$ (normal) é então passado para `glNormal3fv(normal)` antes de desenhar a face (`glVertex3fv`).

#### Configuração de Iluminação (`initGL`)

A iluminação é configurada para simular a interação com o material do objeto:

* **Luz Ambiente, Difusa e Especular:** Parâmetros de cor e intensidade são definidos para a fonte de luz `GL_LIGHT0`.
* **Material:** A **especularidade** (capacidade de brilho) e a **concentração do brilho** (`GL_SHININESS`) são definidas para o material do objeto (`GL_FRONT`).
* **Shading:** O modo de sombreamento é definido como `GL_FLAT` ou `GL_SMOOTH`.

### 💻 Interação

| Ação | Tecla/Mouse | Efeito |
| :--- | :--- | :--- |
| **Ligar/Desligar Iluminação** | Tecla **L** / Tecla **O** | Ativa/Desativa o uso de `GL_LIGHTING`. |
| **Ligar/Desligar Grid** | Tecla **G** | Alterna a exibição do plano de referência (Grid). |
| **Rotação da Cena (X e Y)** | Teclas de Seta (UP/DOWN/LEFT/RIGHT) | Rotação ao redor dos eixos X e Y. |
| **Rotação da Cena (Z)** | Teclas PgUp / PgDn | Rotação ao redor do eixo Z. |
| **Zoom** | Botões Esquerdo/Direito do Mouse | Altera o ângulo de visão (`angleV`) da projeção perspectiva. |

---