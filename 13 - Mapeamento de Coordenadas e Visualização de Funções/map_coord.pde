float Vxmax, Vxmin, Wxmax, Wxmin;
float Vymax, Vymin, Wymax, Wymin;

void setup(){
  size (500,500);
  // limites do mundo
  Wxmin = -5000;
  Wxmax = 5000;
  Wymin = -5000;
  Wymax = 5000;
  // limites da tela
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
  ellipse(XS(1000),YS(1000), 10,10);  
}
