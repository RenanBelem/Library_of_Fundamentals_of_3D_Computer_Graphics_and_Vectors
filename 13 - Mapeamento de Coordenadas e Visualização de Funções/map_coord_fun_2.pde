float Vxmax, Vxmin, Wxmax, Wxmin;
float Vymax, Vymin, Wymax, Wymin;

void setup(){
  size (500,500);
  background(128);
  // limites da tela (Viewport)
  Vxmin = 0;
  Vxmax = width;
  Vymin = 0;
  Vymax = height;
}

// funções para o mapeamento de coordenadas //
float XS(float XW){
    float xs = ((Vxmax-Vxmin)/(Wxmax-Wxmin))*(XW-Wxmin)+Vxmin;
    return xs;
}
float YS(float YW){
    float ys = ((Vymax-Vymin)/(Wymax-Wymin))*(YW-Wymin)+Vymin;
    return height-ys;
}
///////////////////////////////////////////////

void draw() {
  float x, y;
  
  // limites do mundo 1 (World) - senóide
  Wxmin =  0;
  Wxmax = 10;
  Wymin = -2;
  Wymax = +2;
  for(x = Wxmin; x<Wxmax; x=x+0.1) {
    y = sin(x);  fill(random(255),0,0);
    ellipse(XS(x),YS(y), 10,10); 
  }
  // limites do mundo 1 (World) - parábola
  Wxmin =  -30;
  Wxmax =  +30;
  Wymin =    0;
  Wymax = 1000;
  for(x = Wxmin; x<Wxmax; x=x+1) {
    y = pow(x,2);  fill(0,random(255),0);
    ellipse(XS(x),YS(y), 10,10); 
  }  
  
}
