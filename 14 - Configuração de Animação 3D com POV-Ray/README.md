## Configuração de Animação 3D com POV-Ray

Este projeto consiste em arquivos de cena (`.pov`) e arquivos de inicialização (`.ini`) utilizados para renderizar e configurar animações no *ray tracer* **POV-Ray (Persistence of Vision Ray Tracer)**.

### 🎯 Objetivo

Definir a cena 3D (geometria, iluminação, câmera) e especificar os parâmetros de controle de tempo e quadros para a renderização de animações cíclicas.

### 🧱 Estrutura do Projeto

Os arquivos estão separados logicamente em **Cenas** (o que deve ser renderizado) e **Configurações de Animação** (como deve ser renderizado).

| Arquivo | Localização Assumida | Tipo | Descrição |
| :--- | :--- | :--- | :--- |
| **`TDE 1.pov`** | `Animacao/` | Cena POV-Ray | **Cena principal**. Define a câmera, as fontes de luz, o céu (`plane`), o plano de grama e as geometrias animadas (esferas). |
| **`Tde1.ini`** | `Animacao/` | Configuração INI | Parâmetros de animação para **`TDE 1.pov`**. Define o número de quadros, o *clock* inicial/final e a animação cíclica. |
| **`skyscene.pov.bak`** | `CG1/` | Backup de Cena | Backup de um arquivo de cena (`sky03.pov` original) que define a câmera, o sol e balões (esferas) coloridos. |
| **`second.ini`** | `CG1/` | Configuração INI | Parâmetros de animação para a cena `skyscene.pov` (implícito). |

---

### 1. Cena Principal (`TDE 1.pov`)

Este arquivo define o ambiente 3D para a primeira animação:

* **Câmera (`Camera`):** Definida com um ângulo de $80^\circ$ e com sua `location` e `look_at` controladas pela variável `clock` para criar um movimento animado.
* **Luzes (`light_source`):** Múltiplas fontes de luz são definidas, incluindo uma luz spot.
* **Geometria:**
    * Duas esferas com `scale <1, 1.5, 1>` e texturas de cores diferentes (magenta e azul/branco).
    * As esferas possuem animação de translação e rotação controladas pelo `clock`.

### 2. Configuração da Animação (`Tde1.ini`)

Este arquivo define o ciclo de animação para a cena `TDE 1.pov`:

| Parâmetro | Valor | Descrição |
| :--- | :--- | :--- |
| `Input_File_Name` | `TDE 1.pov` | Arquivo de cena a ser renderizado. |
| `Initial_Frame` | 1 | Primeiro quadro a ser renderizado. |
| `Final_Frame` | 36 | Último quadro a ser renderizado (total de 36 quadros). |
| `Initial_Clock` | 0 | Valor inicial da variável de tempo (clock). |
| `Final_Clock` | 3 | Valor final da variável de tempo (clock). |
| `Cyclic_Animation` | `on` | A animação é definida como cíclica. |

### 3. Configuração de Backup (`second.ini` / `skyscene.pov.bak`)

Estes arquivos configuram uma segunda animação, possivelmente usada para testes:

* **`second.ini`**: Define a renderização para **90 quadros** (`Final_Frame=90`), também com `Cyclic_Animation=on`.
* **`skyscene.pov.bak`**: O arquivo de cena (backup) define esferas (`BALAOAZUL`, `BALAOBRANCO`, etc.) em movimento, com suas posições e rotações controladas pela variável `clock`.