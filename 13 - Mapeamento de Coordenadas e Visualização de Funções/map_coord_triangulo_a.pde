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

float P1X = 0, P1Y= 0;
float P2X = 4000, P2Y = P1Y;
float P3X = (P2X-P1X)/2, P3Y = P3X * tan(60*PI/180);

void draw() {
  ellipse(XS(P1X),YS(P1Y), 10,10);  
  ellipse(XS(P2X),YS(P2Y), 10,10); 
  ellipse(XS(P3X),YS(P3Y), 10,10); 
  
  line(XS(P1X),YS(P1Y), XS(P2X),YS(P2Y));
  line(XS(P2X),YS(P2Y), XS(P3X),YS(P3Y));
  line(XS(P3X),YS(P3Y), XS(P1X),YS(P1Y));
}
