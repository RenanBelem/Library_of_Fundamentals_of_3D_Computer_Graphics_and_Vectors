## Biblioteca de Fundamentos de Computação Gráfica 3D e Vetores

Este repositório consolida uma série de projetos e exercícios práticos desenvolvidos em **C++ (OpenGL/GLUT/GLEW)** e **Processing (.pde)**, com foco na compreensão e implementação manual dos fundamentos matemáticos e algorítmicos da Computação Gráfica 3D.

O conteúdo abrange desde a álgebra vetorial e matricial essencial (coordenadas homogêneas, produto vetorial) até técnicas avançadas de renderização (iluminação, projeções e animação).

---

## 1. Álgebra e Transformações 3D (C++)

Esta seção foca na implementação das ferramentas matemáticas necessárias para manipular objetos no espaço 3D, utilizando a classe `Matriz4q` (matrizes $4 \times 4$ em coordenadas homogêneas).

| Projeto | Arquivos Principais | Conceitos Chave |
| :--- | :--- | :--- |
| **Transformações Geométricas 3D** [Projeto 1 & 6] | `main.cpp`, `Matriz4q.h/.cpp`, `Objeto.h/.cpp` | **Transformações Compostas:** Demonstra o encadeamento de Translação, Escala e Rotação para aplicar uma escala relativa ao centro do objeto. Inclui a implementação manual de todas as matrizes de transformação $4 \times 4$. |
| **Operações Matriciais** [Projeto 4 & 9] | `main.cpp`, `Matriz10q.h/.cpp` | **Álgebra Linear:** Implementa operações básicas (`Soma`, `Multiplica`, `Transposta`) em matrizes $4 \times 4$. Demonstra a visualização de dados (cores RGB) em uma matriz $10 \times 10$ como uma grade de cubos 3D. |
| **Produto Vetorial e Normalização** [Projeto 5 & 16] | `main.cpp`, `ClasseVetor.h/.cpp`, `ClassePonto.h/.cpp` | **Cálculo da Normal:** Demonstra como encontrar o vetor **Normal** a um plano definido por três pontos, usando o **Produto Vetorial** e a **Normalização** (para obter um vetor unitário). Fundamental para iluminação. |

---

## 2. Modelagem e Iluminação 3D (C++)

Estes projetos focam na criação de primitivas complexas e na configuração do ambiente de renderização, garantindo que os objetos sejam renderizados sob luz.

| Projeto | Arquivos Principais | Conceitos Chave |
| :--- | :--- | :--- |
| **Iluminação e Normais** [Projeto 3] | `3-main-triangulos-ilum-normais.cpp`, `Triangle.h/.cpp` | **Cálculo de Normais:** Demonstra a diferença entre objetos com e sem `glNormal3fv` sob luz. Implementa a função `calcNormal` (Produto Vetorial) para faces triangulares e normaliza o resultado. |
| **Modelagem Modular (TDE-2)** [Projeto 10] | `TDE-2.cpp`, `Cube.h/.cpp`, `TetraHedro.h/.cpp` | **Estrutura Modular:** Cria classes reutilizáveis (`Cube`, `Cone`, `Disk`, `TetraHedro`) para modelagem, com dependência de uma classe `Triangle` base para calcular o vetor normal de cada face. |
| **Primitivas e Iluminação (TDE Pavão)** [Projeto 7] | `TDE Pavão.cpp`, `Cone.h/.cpp`, `Cube.h/.cpp` | **Composição de Cena:** Configura a fonte de luz e o observador em **Projeção Perspectiva** para renderizar múltiplas primitivas na cena simultaneamente. Inclui interação com teclado para rotação e zoom. |

---

## 3. Projeções, Animação e Algoritmos (OpenGL / Processing)

Estes projetos exploram técnicas de visualização, *ray tracing* e algoritmos de base.

| Projeto | Scripts | Conceitos Chave |
| :--- | :--- | :--- |
| **Projeção Ortogonal** [Projeto 8 & 11] | `main-ortho0.cpp`, `Ex4 cds3d.cpp` | **Projeção:** Demonstra a visualização de modelos 3D usando **Projeção Ortogonal** (`glOrtho`), onde as dimensões do objeto não variam com a distância. Inclui manipulação de rotação e zoom. |
| **Simulação Física** [Projeto 2] | `main_2.cpp`, `ClasseVetor.cpp` | **Animação Vetorial:** Simulação de um objeto 3D sob influência da `gravidade` (aceleração vetorial). Demonstra a integração de Posição + Velocidade e a gestão de colisões com os limites da cena. |
| **Animações POV-Ray** [Projeto 17 & 19] | `anima-vai-volta.pov`, `Tde1.ini`, etc. | **Animação Cíclica:** Uso da variável **`clock`** e arquivos `.ini` para renderizar animações cíclicas, movimentos de "vai e volta" (ping-pong) e movimento circular. Inclui *ray tracing* de esferas e objetos compostos. |
| **Mapeamento de Coordenadas** [Projeto 13] | `map_coord_fun.pde`, `movimento_parabolico.pde`, etc. | **Gráficos 2D:** Implementa as funções manuais de mapeamento de coordenadas **World $\to$ Viewport** (`XS`, `YS`). Utiliza esse mapeamento para visualizar funções matemáticas (`senoide`, `parabola`, `tangente`) e animar movimentos. |
| **Algoritmos Gráficos** [Projeto 12] | `desenha_retas_clipping.pde`, `Insert_sort.pde`, `lei_Lambert.pde` | **Fundamentos Algorítmicos:** Implementação do algoritmo de recorte **Cohen-Sutherland**, cálculo da **Lei de Lambert** para iluminação e algoritmos de **Insertion Sort** para ordenação de listas e matrizes. |

---
