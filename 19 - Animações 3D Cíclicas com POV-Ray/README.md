## Animações 3D Cíclicas com POV-Ray

Este projeto é um conjunto de arquivos de cena (`.pov`) e configuração (`.ini`) desenvolvidos para o *ray tracer* **POV-Ray (Persistence of Vision Ray Tracer)**, com foco em criar e controlar diferentes tipos de **animações 3D**. O principal mecanismo de controle é a variável de tempo **`clock`**, que varia de acordo com os parâmetros definidos no arquivo `.ini`.

### 🎯 Objetivo Principal

Demonstrar a criação de animações cíclicas (looping), animações simples de translação linear, translação de "vai e volta" e movimento circular, todas controladas pela variável `clock`.

### 🧱 Estrutura dos Arquivos

Os arquivos estão organizados para demonstrar quatro tipos principais de animação:

| Arquivo(s) | Foco | Técnica Principal |
| :--- | :--- | :--- |
| **`anima-simples.pov`** | Rotação/Cena Cíclica | Define a cena principal com uma esfera e um *torus*. O `light_source` tem sua posição animada pelo `clock`. |
| **`anima-vai-volta.pov`** | Translação Ping-Pong | Usa diretivas condicionais (`#switch`, `#range`) para forçar um objeto a se mover em uma trajetória de ida e volta sobre o eixo X, dividindo o ciclo do `clock` em duas fases. |
| **`anima-circ-01.pov`** | Movimento Circular | Usa funções trigonométricas (`sin` e `cos`) aplicadas ao `clock` (ou `Angulo`) para mover um objeto em uma trajetória circular (ou elíptica). |
| **`anima-2objs.pov`** | Animação Coordenada | Duas esferas se movem em sentidos opostos (`PosX` e `50-PosX`), demonstrando o uso da mesma variável `clock` para animar múltiplos objetos de forma coordenada. |

### 💡 Controle de Animação com `clock`

A variável `clock` é a base de todas as animações. Ela varia linearmente de `Initial_Clock` a `Final_Clock` ao longo dos quadros definidos.

#### 1\. Translação de "Vai e Volta" (`anima-vai-volta.pov`)

Este arquivo ilustra como transformar uma variável de tempo linear (`clock` de 0 a 1) em um movimento de ping-pong (ida e volta):

  * **Fase 1 (IDA):** De `clock = 0.0` a `0.5`, o valor de `PosX` é diretamente `xfactor` (move-se para a direita).
  * **Fase 2 (VOLTA):** De `clock = 0.5` a `1.0`, o valor de `PosX` é calculado como `0.5 - (xfactor - 0.5)` (move-se para a esquerda).

A diretiva `#debug` é usada para imprimir o estado (`"IDA"` ou `"VOLTA"`) no console durante a renderização.

#### 2\. Configurações INI (`anima-vai-volta.ini`)

O arquivo `.ini` define os parâmetros de renderização para a animação de ping-pong:

| Parâmetro | Valor | Descrição |
| :--- | :--- | :--- |
| `Input_File_Name` | `anima-vai-volta.pov` | Arquivo de cena a ser renderizado. |
| `Final_Frame` | 30 | O número total de quadros na animação. |
| `Initial_Clock`/`Final_Clock` | 0 / 1 | O `clock` varia de 0 a 1, permitindo que a animação seja dividida ao meio (0 a 0.5 para ida, 0.5 a 1.0 para volta). |

#### 3\. Movimento Circular (`anima-circ-01.pov`)

O movimento é definido fora do bloco `object` e aplicado no bloco `translate` do objeto, usando funções trigonométricas:

```pov
#declare Angulo = Start+(End-Start)*clock;
// ...
translate <Raio*sin(radians(Angulo)), 0, Raio*cos(radians(Angulo))>
```

*Esta lógica não está totalmente visível, mas é a forma canônica de usar `sin` e `cos` aplicados à variável `clock` (`Angulo`) para gerar uma translação circular nos eixos XZ.*

-----