## POV-Ray: Modelagem e Animação de Cenas 3D

Este projeto consiste em um conjunto de arquivos de cena (`.pov`) e configuração (`.ini`) desenvolvidos para o *ray tracer* **POV-Ray (Persistence of Vision Ray Tracer)**. O foco está na criação de cenas 3D estáticas e na definição de parâmetros de tempo para renderização de animações.

### 🎯 Objetivo Principal

Definir a geometria, texturas, câmeras e iluminação de várias cenas 3D, e configurar uma animação cíclica com controle de quadros e tempo (variável `clock`).

### 🧱 Estrutura do Código

O projeto inclui várias cenas e arquivos de inicialização, cada um com um propósito específico:

| Arquivo | Tipo | Descrição |
| :--- | :--- | :--- |
| **`ExAnimacao.pov`** | Cena Principal (Animação) | Arquivo de cena que contém a geometria animada principal (provavelmente uma esfera, dado o snippet). |
| **`ExAnimacao.ini`** | Configuração INI | Define os parâmetros de tempo e quadros para renderizar a animação cíclica de `ExAnimacao.pov`. |
| **`cena.pov`** | Cena Estática (Múltiplas Esferas) | Cena de teste que define um plano de fundo quadriculado (verde e marrom) e múltiplas esferas com texturas simples. |
| **`esfera.pov`** | Cena Estática (Esfera Simples) | Cena simples focada em renderizar uma única esfera amarela. |
| **`cone.pov` / `cone.pov.bak`** | Cena Estática (Esfera em Loop) | Cena de teste com a câmera e luz definidas, e um *loop* (infinito, `while true`) que tenta renderizar esferas em movimento. |
| **`teste.pov`** | Cena Estática (Estrutura de Teste) | Cena de teste estruturada com plano de fundo quadriculado, luz amarela e múltiplas esferas. |

---

### 1. Configuração da Animação (`ExAnimacao.ini`)

O arquivo `.ini` é usado pelo POV-Ray para controlar o processo de renderização da animação:

| Parâmetro | Valor | Função |
| :--- | :--- | :--- |
| `Input_File_Name` | `ExAnimacao.pov` | Arquivo de cena a ser processado. |
| `Initial_Frame` | 1 | Primeiro quadro. |
| `Final_Frame` | 30 | Último quadro (o ciclo terá 30 quadros). |
| `Initial_Clock` | 1 | Valor inicial da variável `clock` (que controla a animação na cena). |
| `Final_Clock` | 360 | Valor final da variável `clock` (permite que o objeto gire $360^\circ$ ao longo da animação). |

### 2. Modelagem e Elementos Comuns (`.pov` files)

Os arquivos de cena `.pov` utilizam uma sintaxe declarativa para construir o mundo 3D.

#### Câmera e Iluminação
* A maioria das cenas define a câmera usando `location` (posição) e `look_at` (ponto focal).
* Fontes de luz (`light_source`) são definidas, geralmente com a cor `White` ou `Yellow`.

#### Primitivas Geométricas
* **`sphere`:** Usada amplamente em `cena.pov`, `esfera.pov` e `teste.pov` para criar os objetos principais.
* **`plane`:** Usada em `cena.pov` e `teste.pov` para definir um chão ou plano de fundo com textura quadriculada (`checker`).

#### Texturas
As texturas são aplicadas usando blocos `texture` contendo:
* **`pigment`:** Define a cor ou padrão.
* **`finish`:** Define as propriedades de reflexão (difuse, phong, etc.).

---