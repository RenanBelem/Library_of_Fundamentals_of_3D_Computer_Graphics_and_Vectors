float Vxmax, Vxmin, Wxmax, Wxmin;
float Vymax, Vymin, Wymax, Wymin;

void setup(){
  size (500,500);
  background(128);
  noStroke();
  // limtes do mundo
  Wxmin =  0;
  Wxmax = 25;  // aumentando este valor, diminui a distância entre as linhas
  Wymin = -2;
  Wymax = +2;
  // limites da tela (Viewport)
  Vxmin = 0;
  Vxmax = width;
  Vymin = 0;
  Vymax = height;
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
  float x, y;
  for(x = Wxmin; x<Wxmax; x=x+0.01) {
    y = tan(x);
    ellipse(XS(x),YS(y), 10,10);
  } 
}
