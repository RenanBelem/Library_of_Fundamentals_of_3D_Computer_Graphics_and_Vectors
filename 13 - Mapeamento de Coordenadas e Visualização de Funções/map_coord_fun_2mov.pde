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
float x1, y1, x2, y2;

void draw() {
  background(128);
  // limites do mundo 1 (World) - senóide
  Wxmin =  0;
  Wxmax = 10;
  Wymin = -2;
  Wymax = +2;

    y1 = sin(x1);  fill(255,0,0);
    ellipse(XS(x1),YS(y1), 10,10);
    if (x1<Wxmax) x1=x1+0.1; else x1=Wxmin;

  // limites do mundo 1 (World) - parábola
  Wxmin =  -30;
  Wxmax =  +30;
  Wymin =    0;
  Wymax = 1000;

    y2 = pow(x2,2);  fill(0,255,0);
    ellipse(XS(x2),YS(y2), 10,10); 
    if (x2<Wxmax) x2=x2+1; else x2=Wxmin;
}  
