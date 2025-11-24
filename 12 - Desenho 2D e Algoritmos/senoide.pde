float x = -10*PI;
float y = 0;
int cont = 0;

void setup(){
  size(700, 500);
  noStroke();
  background(0);
}
void draw(){
  translate(width/2, height/2);
  x = x + PI/20;
  y = sin(x);
  ellipse(x*10, y*100, 2, 2);
  if(cont>400) { x=-10*PI; y=0; cont=0; background(0);}
  cont++;
  println(x, y);
}
