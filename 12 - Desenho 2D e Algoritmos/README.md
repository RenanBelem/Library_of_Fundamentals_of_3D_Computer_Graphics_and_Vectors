## Fundamentos de Computação Gráfica: Desenho 2D e Algoritmos (Processing .pde)

Este projeto em **Processing (.pde)** agrupa diversos exercícios focados em implementar algoritmos e técnicas fundamentais de computação gráfica e matemática, como desenho de primitivas, recorte (clipping), ordenação e modelagem de funções matemáticas.

### 🎯 Objetivo

Demonstrar a implementação manual de algoritmos básicos (como сортиção por inserção, Lei de Lambert) e técnicas de visualização 2D (como senoide, parábola, recorte de retas e triangulação).

### 🧱 Estrutura do Código

O projeto consiste em arquivos `.pde` individuais, cada um focado em uma funcionalidade específica:

| Arquivo | Foco da Demonstração | Conceito Central |
| :--- | :--- | :--- |
| **`senoide.pde`** | Desenho de Curvas | Desenha uma curva Senoide (`y = sin(x)`) no plano cartesiano, utilizando um *loop* e a função `translate()` para centralizar o gráfico. |
| **`parabola.pde`** | Desenho de Curvas | Desenha uma curva Parabólica (`y = -0.05 * pow(x, 2)`) usando pequenos pontos (`ellipse`). |
| **`Insert_sort.pde`** | Algoritmo de Ordenação | Implementação do algoritmo de ordenação **Insertion Sort** para um *array* unidimensional de inteiros (`int[]`). |
| **`Insert_sort2.pde`** | Algoritmo de Ordenação | Implementação do **Insertion Sort** adaptado para ordenar as linhas de uma **matriz bidimensional** (`int[][]`) com base nos valores de uma coluna específica (`c`). |
| **`lei_Lambert.pde`** | Modelagem de Iluminação | Implementa o cálculo básico da **Lei de Lambert** para determinar a intensidade da luz refletida em uma face (`calcRaioRef()`), considerando a distância e o ângulo de incidência da fonte luminosa (Luz Ambiente e Luz Difusa). |
| **`desenha_retas_clipping.pde`** | Recorte (Clipping) | Demonstra a implementação do algoritmo **Cohen-Sutherland** para o recorte de retas. Calcula códigos para determinar a posição da reta em relação a uma janela de visualização (`x_min`, `x_max`, `y_min`, `y_max`). |
| **`desenha_triangulos.pde`** | Geometria 3D e Ordenação | Define pontos 3D e os agrupa em triângulos. Inclui uma função adaptada de **Insertion Sort** (`insertSort`) para ordenar triângulos (embora a coluna de ordenação não esteja especificada no método). |

### 📈 Lógica e Algoritmos

#### Lei de Lambert (`lei_Lambert.pde`)
O cálculo da intensidade da luz refletida (`calcRaioRef()`) inclui:
* **Luz Ambiente:** `Ia * Ka` (Intensidade Ambiente * Coeficiente de Reflexão Ambiente).
* **Luz Difusa:** `Id * Kd * cos(anguloIncidencia)` (Intensidade Difusa * Coeficiente de Reflexão Difusa * Cosseno do Ângulo de Incidência).
* **Atenuação:** A intensidade é atenuada pela distância.

#### Recorte de Retas (`desenha_retas_clipping.pde`)
* O código define códigos de 4 bits (`INSIDE_`, `LEFT_`, `RIGHT_`, `BOTTOM_`, `TOP_`) para indicar a posição de um ponto em relação à janela de recorte.
* A função `computeCode(x, y)` calcula esses códigos. Retas fora da janela são processadas para encontrar a intersecção.