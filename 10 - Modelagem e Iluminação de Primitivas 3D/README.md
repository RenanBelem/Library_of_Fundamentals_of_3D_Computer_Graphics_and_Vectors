## Projeto de Computação Gráfica: Modelagem e Iluminação de Primitivas 3D (TDE-2)

Este projeto em C++ com **OpenGL (via GLUT/GLEW)** implementa um conjunto modular de classes para modelar, desenhar e interagir com diversas primitivas geométricas 3D. O foco principal é a aplicação correta da **Projeção Perspectiva** e o cálculo dos **Vetores Normais** para simular iluminação de forma realista.

### 🎯 Objetivo Principal

Construir uma biblioteca de classes (incluindo `Cube`, `TetraHedro`, `Cone` e `Disk`) onde cada primitiva implementa a lógica necessária para o desenho e, crucialmente, o cálculo do **Vetor Normal** para interagir com a fonte de luz.

### 🧱 Estrutura e Classes de Geometria

O projeto é baseado em uma estrutura modular, onde a classe `Triangle` é a base para o cálculo de normais, e as demais classes modelam as primitivas.

| Arquivo | Classe | Foco na Implementação |
| :--- | :--- | :--- |
| **`Triangle.h` / `Triangle.cpp`** | `Triangle` | **Base de Geometria/Iluminação.** Implementa o **Cálculo do Vetor Normal** (Produto Vetorial) entre vetores de aresta e sua subsequente **Normalização** (vetor unitário). |
| **`TetraHedro.h` / `TetraHedro.cpp`** | `TetraHedro` | Modela o **Tetraedro** (4 faces triangulares). Sua função `Desenha()` utiliza a lógica do `Triangle` para definir as normais de cada face. |
| **`Cube.h` / `Cube.cpp`** | `Cube` | Modela o **Cubo** a partir de 12 triângulos (ou faces). A classe define e aplica os vetores normais para cada face. |
| **`Cone.h` / `Cone.cpp`** | `Cone` | Modelagem e desenho do **Cone** (incluindo base e faces laterais triangulares). |
| **`Disk.h` / `Disk.cpp`** | `Disk` | Modelagem do **Disco** (base planar). Sua normal é frequentemente definida como um valor óbvio (`0, 0, 1`) ou calculada a partir de triângulos para maior precisão. |
| **`TDE-2.cpp`** | N/A | **Driver Principal.** Instancia todas as primitivas, configura a cena 3D e o sistema de iluminação. |

### 💡 Iluminação e Projeção (`TDE-2.cpp`)

O arquivo principal configura o ambiente para simular um espaço 3D realista:

* **Projeção:** Utiliza **Projeção Perspectiva** (`gluPerspective`) para simular a profundidade, com um volume de visualização definido.
* **Iluminação:** O ambiente está habilitado para `GL_LIGHTING` e `GL_DEPTH_TEST` (teste de profundidade), o que torna crucial que todas as primitivas tenham seus vetores normais definidos corretamente (função da classe `Triangle`) para renderizar sombreamento.
* **Interação:** O código inclui as funções de *callback* (`processSpecialKeys`, `mouse`) para manipular a rotação da cena (eixos X, Y, Z) e o zoom.

### 🛠 Ferramentas de Projeto

Os arquivos de projeto (`.sln`, `.vcxproj`, etc.) indicam que este é um projeto **Microsoft Visual Studio**, que facilita a compilação e linkagem das bibliotecas GLUT/GLEW necessárias para o desenvolvimento em OpenGL.

---