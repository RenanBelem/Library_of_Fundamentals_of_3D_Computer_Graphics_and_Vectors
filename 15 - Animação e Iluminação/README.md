## Fundamentos de Computação Gráfica: Animação e Iluminação (C++ / OpenGL)

Este projeto em C++ com **OpenGL (via GLUT/GLEW)** agrupa quatro arquivos de demonstração focado em técnicas de animação, iluminação e manipulação da perspectiva 3D (câmera e zoom).

### 🎯 Objetivo

Demonstrar a diferença entre animação contínua (automática) e animação interativa (manual), e configurar o ambiente de iluminação e profundidade.

### 🧱 Estrutura dos Arquivos

| Arquivo | Foco Principal | Técnica Utilizada |
| :--- | :--- | :--- |
| **`main_anim1.cpp`** | **Animação Contínua** | Usa `glutTimerFunc(25, update, 0)` para um incremento automático e constante do ângulo de rotação (`rAngle`) a cada 25ms, gerando uma animação de *loop*. |
| **`main_anim2.cpp`** | **Animação Interativa** | O ângulo de rotação (`angle` e `angle1`) é alterado manualmente pelas setas do teclado (função `processSpecialKeys`). |
| **`main_ilum1.cpp`** | **Iluminação Perspectiva** | Configura um ambiente de iluminação (`GL_LIGHTING`) com projeção perspectiva, luz ambiente, difusa e especular para renderizar primitivas (ex: `glutSolidTeapot`). |
| **`main-keycamzoom1.cpp`** | **Controle de Câmera/Zoom** | Implementa funções para manipulação da perspectiva (zoom in/out via mouse) e rotação da cena (eixos X, Y e Z via teclado). |

---

### 1. Animação e Profundidade

Os arquivos de animação (`main_anim1.cpp` e `main_anim2.cpp`) utilizam:

* **Teste de Profundidade:** Ambos ativam o teste de profundidade (`glEnable(GL_DEPTH_TEST)`) e `GL_DOUBLE` *buffering*, essenciais para renderizar objetos 3D de forma correta.
* **Animação Contínua (`main_anim1.cpp`):** O objeto rotaciona automaticamente usando `glutTimerFunc`. A animação é contínua e cíclica (o ângulo reseta após 360 graus).
* **Animação Interativa (`main_anim2.cpp`):** O redesenho é forçado apenas quando o usuário interage (`glutPostRedisplay`).

### 2. Iluminação (`main_ilum1.cpp`)

Este arquivo configura um ambiente básico de iluminação 3D:

* **Projeção:** O modo de projeção é **Perspectiva** (`gluPerspective`), adequado para visualização de profundidade.
* **Fonte de Luz:** Uma fonte de luz (`GL_LIGHT0`) é definida com:
    * Luz ambiente (`GL_AMBIENT`).
    * Luz difusa (`GL_DIFFUSE`).
    * Luz especular (`GL_SPECULAR`).
* **Objetos:** Primitivas como `glutSolidTeapot` e `glutSolidCube` são desenhadas sob esta iluminação.

### 3. Controle de Viewport e Zoom (`main-keycamzoom1.cpp`)

Este arquivo foca na manipulação interativa da cena:

* **Controles de Zoom:** O zoom é implementado alterando a variável `zoom`.
* **Controles de Rotação:** O teclado controla a rotação da cena (câmera) alterando as variáveis `angle` e `angle1`.
* **Projeção:** A projeção utilizada é **Ortogonal** (fixa), mas as rotações e zoom são aplicados na matriz `GL_MODELVIEW`.

---