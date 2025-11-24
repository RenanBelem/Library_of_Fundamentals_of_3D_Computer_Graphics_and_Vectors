float Vxmax, Vxmin, Wxmax, Wxmin;
float Vymax, Vymin, Wymax, Wymin;

void setup(){
  size (500,500);
  background(128);
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
  
  // limites da tela (Viewport1)
  Vxmin = 0;
  Vxmax = width/2;
  Vymin = 0;
  Vymax = height/2;  
  // limites do mundo (World1) - senóide
  Wxmin =  0;
  Wxmax = 10;
  Wymin = -2;
  Wymax = +2;
  // desenha a Viewport1
  fill(0);
  rect(Vxmin, height-Vymax, Vxmax-Vxmin, Vymax-Vymin);
  fill(255);
  text("Viewport 1",Vxmin,height-Vymin);
  for(x = Wxmin; x<=Wxmax; x=x+0.1) {
    y = sin(x);  fill(0,255,0);
    ellipse(XS(x),YS(y), 5,5); 
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////
  // limites da tela (Viewport2)
  Vxmin = width/2;
  Vxmax = width;
  Vymin = height/2;
  Vymax = height;
  // limites do mundo (World2) - parábola
  Wxmin =  -30;
  Wxmax =  +30;
  Wymin =    0;
  Wymax = 1000;
  // desenha borda da Viewport2
  fill(0);
  rect(Vxmin, height-Vymax, Vxmax-Vxmin, Vymax-Vymin);
  fill(255);
  text("Viewport 2",Vxmin,height-Vymin);
  for(x = Wxmin; x<=Wxmax; x=x+1) {
    y = pow(x,2);  fill(255,0,0);
    ellipse(XS(x),YS(y), 5,5); 
  }  
  
}
