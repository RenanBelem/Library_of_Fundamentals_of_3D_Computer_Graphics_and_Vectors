
float x = -50;
float y = 0;
int cont = 0;

void setup(){
  size(600, 600);
  noStroke();
  background(0);
}
void draw(){
  translate(width/2, height/2);
  x++;
  y= -0.05*pow(x, 2);
  ellipse(x,y,2,2);
  
  if (cont>100) { x=-50; y=0; cont=0;}
  cont++;
  println(x,y);
}
