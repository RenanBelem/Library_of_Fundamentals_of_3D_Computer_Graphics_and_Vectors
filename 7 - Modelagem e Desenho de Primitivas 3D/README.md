## Projeto de Computação Gráfica: Modelagem e Desenho de Primitivas 3D

Este projeto em C++ utiliza **OpenGL (via GLUT/GLEW)** para modelar, desenhar e interagir com diversas primitivas geométricas 3D complexas, como o **Cubo**, o **Tetraedro**, o **Triangulo**, o **Disco** e o **Cone**. O foco é na implementação detalhada do desenho dessas primitivas e na gestão correta de seus **Vetores Normais** para iluminação.

### 🎯 Objetivo

Criar classes modulares para cada primitiva 3D, implementar a lógica de triangulação e cálculo de normais para que os objetos sejam renderizados corretamente sob a influência de uma fonte de luz. O arquivo principal (`cena_principal.cpp`) serve como a cena de demonstração e interação.

### 🧱 Estrutura do Código

O projeto é baseado em classes que representam os objetos 3D e contém o ambiente principal de renderização:

| Arquivo | Classe | Foco na Implementação |
| :--- | :--- | :--- |
| **`cena_principal.cpp`** | N/A | Arquivo principal que configura o ambiente OpenGL (projeção perspectiva, iluminação, observador) e contém a função `render()` para desenhar todas as primitivas na cena. |
| **`Cube.h`/`.cpp`** | `Cube` | Define um **cubo** usando 12 triângulos (6 faces x 2 triângulos) e implementa o desenho dos **Vetores Normais** unitários para cada face no centro. |
| **`TetraHedro.h`/`.cpp`** | `TetraHedro` | Define e desenha um **tetraedro** (4 faces triangulares), implementando o cálculo manual do **Vetor Normal** para cada face. |
| **`Triangulo.h`/`.cpp`** | `Triangulo` | Define e desenha um **triangulo**, implementando o cálculo manual para cada lado. |
| **`Disk.h`/`.cpp`** | `Disk` | Define e desenha um **disco** 2D (círculo preenchido) no plano XY. O vetor normal é fixo (0, 0, 1) e desenhado no centro. |
| **`Cone.h`/`.cpp`** | `Cone` | Define e desenha a **base de um cone** (um disco) e as faces laterais triangulares que ligam a base ao vértice. |

### 💡 Iluminação e Normais

A correta aplicação do vetor normal é essencial para que o modelo 3D interaja de forma realista com a fonte de luz.

* **Cálculo da Normal:** Para o `TetraHedro` e o `Cube`, a implementação exige que o vetor normal seja calculado para cada face triangular através do **Produto Vetorial** entre dois vetores aresta da face.
* **Normal Unitária:** A normal resultante é **normalizada** (tornada unitária) e definida no OpenGL usando `glNormal3fv()` antes de especificar os vértices da face.
* **Fonte de Luz:** A cena principal (`cena_principal.cpp`) configura a iluminação ambiente, difusa e especular (`GL_LIGHT0`) e posiciona a luz, forçando os objetos a exibir as diferenças de sombreamento baseadas em suas normais.

### 💻 Interação e Visualização (`cena_principal.cpp`)

O arquivo principal configura uma **projeção perspectiva** e permite ao usuário manipular a cena para inspecionar os objetos sob a luz.

| Ação | Tecla/Mouse | Efeito |
| :--- | :--- | :--- |
| **Ligar/Desligar Iluminação** | Tecla **L** / Tecla **O** | Ativa/Desativa o uso de `GL_LIGHTING`. |
| **Ligar/Desligar Grid** | Tecla **G** | Alterna a exibição do plano de referência (Grid). |
| **Rotação da Cena (X e Y)** | Teclas de Seta (UP/DOWN/LEFT/RIGHT) | Rotação ao redor dos eixos X e Y. |
| **Rotação da Cena (Z)** | Teclas PgUp / PgDn | Rotação ao redor do eixo Z. |
| **Zoom** | Botões Esquerdo/Direito do Mouse | Altera o ângulo de visão (`angleV`) da projeção perspectiva. |

---