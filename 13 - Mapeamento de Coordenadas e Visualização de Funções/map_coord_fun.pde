float Vxmax, Vxmin, Wxmax, Wxmin;
float Vymax, Vymin, Wymax, Wymin;

void setup(){
  size (500,500);
  // limites do mundo (World)
  Wxmin = -30;
  Wxmax = 30;
  Wymin = 0;
  Wymax = 1000;
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
  for(int i = -30; i<30; i++) {
    x = i;
    y = pow(x,2);  
    ellipse(XS(x),YS(y), 10,10); 
    println (x,y);
  }
}
