## Fundamentos de Computação Gráfica 2D: Mapeamento de Coordenadas e Visualização de Funções

Este projeto em **Processing (.pde)** agrupa exercícios que demonstram o conceito fundamental da **transformação de coordenadas** (World para Viewport) e a aplicação dessas transformações para visualizar funções matemáticas e simular movimentos 2D.

### 🎯 Objetivo Principal

Implementar manualmente as funções de mapeamento que convertem coordenadas de um sistema matemático abstrato (Mundo, $W$) para as coordenadas de pixel na tela (Viewport, $V$), e utilizar essa conversão para desenhar gráficos e animar objetos.

***

### 💡 Conceito Central: Mapeamento World $\leftrightarrow$ Viewport

A maioria dos *scripts* define a transformação usando as variáveis de limite:

* **Mundo (World - $W$):** Define o sistema de coordenadas matemático (`Wxmin`, `Wxmax`, `Wymin`, `Wymax`).
* **Tela (Viewport - $V$):** Define a área de pixel onde o desenho ocorrerá (`Vxmin`, `Vxmax`, `Vymin`, `Vymax`).

As funções de conversão são:

| Função | Finalidade | Fórmula Aplicada (Implementação) |
| :--- | :--- | :--- |
| `XS(float XW)` | Converte a coordenada X do Mundo ($X_W$) para a coordenada X da Tela ($X_S$). | $\text{X}_\text{S} = \frac{V_{x\max} - V_{x\min}}{W_{x\max} - W_{x\min}} (X_W - W_{x\min}) + V_{x\min}$ |
| `YS(float YW)` | Converte a coordenada Y do Mundo ($Y_W$) para a coordenada Y da Tela ($Y_S$). | $\text{Y}_\text{S} = \text{height} - \left( \frac{V_{y\max} - V_{y\min}}{W_{y\max} - W_{y\min}} (Y_W - W_{y\min}) + V_{y\min} \right)$ |

***

### 🧱 Arquivos de Demonstração

Os arquivos estão categorizados por seu foco na demonstração:

#### 1. Mapeamento Fundamental e Geometria

| Arquivo | Descrição |
| :--- | :--- |
| **`map_coord.pde`** | Implementação mais básica das funções `XS` e `YS` com um alcance de mundo grande (`-5000` a `5000`). |
| **`map_coord_triangulo.pde`** | Usa o mapeamento para desenhar os vértices de um **triângulo equilátero**. |
| **`map_coord_triangulo_a.pde`** | Versão alternativa da triangulação, calculando as coordenadas do terceiro ponto (`P3Y`) usando a tangente ($\text{tan}(60^\circ)$). |

#### 2. Visualização de Funções Matemáticas

Estes scripts ajustam os limites do mundo ($W$) para encaixar a faixa de domínio e imagem da função matemática no *viewport*.

| Arquivo | Função Visualizada | Observações |
| :--- | :--- | :--- |
| **`map_coord_fun.pde`** | Função quadrática (Parábola): $\text{y} = \text{pow}(\text{x}, 2)$. | Limites do Mundo: X de `-30` a `30`; Y de `0` a `1000`. |
| **`map_coord_tangente.pde`** | Função Tangente: $\text{y} = \text{tan}(\text{x})$. | |
| **`map_coord_fun_2.pde`** | **Múltiplas Funções:** Desenha uma **senoide** e uma **parábola** no mesmo *viewport*. | O mapeamento World $\to$ Viewport é redefinido para a parábola após desenhar a senoide. |
| **`map_coord_fun_2Viewports.pde`** | **Múltiplos Viewports:** Demonstra o desenho da senoide e da parábola em **duas áreas de tela separadas** (Viewports diferentes). | |

#### 3. Simulação e Animação

| Arquivo | Conceito | Observações |
| :--- | :--- | :--- |
| **`map_coord_fun_2mov.pde`** | **Animação de Gráfico:** Move dois pontos ao longo de uma senoide e uma parábola em um ciclo contínuo, demonstrando o mapeamento dinâmico. | |
| **`movimento_parabolico.pde`** | **Animação Cinética:** Simula um objeto que se move horizontalmente (`xPos++`) e salta parabolicamente após atingir um ponto fixo, ilustrando um movimento balístico mapeado. | |