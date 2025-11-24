## Projeto de Computação Gráfica: Modelagem e Iluminação de Primitivas 3D

Este projeto em C++ com **OpenGL (via GLUT/GLEW)** é um conjunto modular de classes projetadas para a modelagem, desenho e correta iluminação de primitivas geométricas 3D. O foco principal é o cálculo preciso dos **Vetores Normais** para cada face.

### 🎯 Objetivo

Criar uma biblioteca de classes reutilizáveis (`Cube`, `Cone`, `TetraHedro`, `Disk`) que implementam a geometria de forma detalhada (usando triângulos) e incluem o cálculo manual do Vetor Normal para interação correta com fontes de luz.

### 🧱 Estrutura do Código (Modelo Modular)

As primitivas geométricas são definidas em pares de arquivos `.h` e `.cpp`. Todos os arquivos de cabeçalho (`.h`) dependem de definições básicas (como `PI` e `Triangle.h`).

| Arquivo | Classe | Funcionalidade Principal |
| :--- | :--- | :--- |
| **`Triangle.h` / `Triangle.cpp`** | `Triangle` | **Classe Base de Geometria.** Define um triângulo (3 vértices) e implementa o **cálculo do Vetor Normal** (Produto Vetorial) e sua normalização (vetor unitário). |
| **`TetraHedro.h` / `TetraHedro.cpp`** | `TetraHedro` | Modela o tetraedro a partir de 4 faces triangulares. Sua implementação depende do `Triangle` para o cálculo das normais. |
| **`Cube.h` / `Cube.cpp`** | `Cube` | Modela um cubo a partir de 12 triângulos (2 por face) e implementa a lógica de desenho, aplicando as normais para cada face. |
| **`Disk.h` / `Disk.cpp`** | `Disk` | Modela um disco (círculo 2D/3D). Usa `GL_TRIANGLE_FAN` ou similar para o desenho. A normal é definida como óbvia (e.g., `(0, 0, 1)` para um disco no plano XY). |
| **`Cone.h` / `Cone.cpp`** | `Cone` | Modela um cone, desenhando a base (como um disco) e as faces laterais triangulares. |

### 💡 Implementação do Vetor Normal

O coração da iluminação correta está na classe `Triangle`:

1.  **Cálculo da Normal:** O método `Triangle::Triangle(...)` calcula o vetor normal $\vec{N}$ da face usando o **Produto Vetorial** entre dois vetores de aresta formados pelos vértices (`v1 = P0 - P1` e `v2 = P2 - P1`).
2.  **Normalização:** O vetor normal resultante é **normalizado** (escalado para ter magnitude 1).
3.  **Desenho:** O vetor normal unitário (`normal[3]`) é então usado pelo OpenGL (`glNormal3fv()`) nas funções de desenho de primitivas (implementadas em `Cube.cpp`, `TetraHedro.cpp`, etc.).

### 🛠 Arquivos de Projeto

Os arquivos de projeto (`.sln`, `.vcxproj`, `.vcxproj.filters`, `.vcxproj.user`) indicam que este código foi desenvolvido e compilado usando o ambiente **Microsoft Visual Studio**, que gerencia as dependências do OpenGL/GLUT/GLEW.

---