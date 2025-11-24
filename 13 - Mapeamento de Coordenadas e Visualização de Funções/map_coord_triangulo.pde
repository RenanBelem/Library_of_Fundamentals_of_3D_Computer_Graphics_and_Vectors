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
  
  strokeWeight(2);
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
  ellipse(XS(3000),YS(1000), 10,10); 
  ellipse(XS(2000),YS(1500*tan(60*PI/180)), 10,10); // 1500 é a coordenada em X do cateto adjacente
                                                    // não confundir com o comprimento do cateto adjacente, que é 1000
  line(XS(1000),YS(1000), XS(3000),YS(1000));
  line(XS(3000),YS(1000), XS(2000),YS(1500*tan(60*PI/180)));
  line(XS(2000),YS(1500*tan(60*PI/180)),XS(1000),YS(1000));
}
