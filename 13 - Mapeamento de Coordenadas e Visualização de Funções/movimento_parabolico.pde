float Vxmax, Vxmin, Wxmax, Wxmin;
float Vymax, Vymin, Wymax, Wymin;
float xPos, yPos; 
float contX;

void setup(){
  size (800,500);
  // limites do mundo (World)
  Wxmin = -40;
  Wxmax = 40;
  Wymin = 0;
  Wymax = 1000;
  // limites da tela (Viewport)
  Vxmin = 0;
  Vxmax = width;
  Vymin = 0;
  Vymax = height;
  // inicialização da posição do objeto e da variável contador
  xPos  = Wxmin;
  yPos  = Wymin;
  contX = 0;  // assume o valor em X do objeto
}

float XS(float XW){
    float xs = ((Vxmax-Vxmin)/(Wxmax-Wxmin))*(XW-Wxmin)+Vxmin;
    return xs;
}

float YS(float YW){
    float ys = ((Vymax-Vymin)/(Wymax-Wymin))*(YW-Wymin)+Vymin;
    return height-ys;
}

void draw() {
    background(0);
// o X é incrementado normalmente, o Y depende da posição do X
// na primeira metade da tela o Y não varia, depois varia como parábola simples
    if (xPos<Wxmax) xPos++; else {xPos = Wxmin; yPos = 0; contX=0; }
    if (xPos>(Wxmax-abs(Wxmin))/2) {contX++;  yPos = pow(contX,2);}
    ellipse(XS(xPos),YS(yPos), 20,20); 
}
