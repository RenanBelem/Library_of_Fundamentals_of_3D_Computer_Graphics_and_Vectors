// Lei de Lambert

float Ia = 1.0; // intensidade da Luz Ambiente
float Id = 1.0; // intensidade da Luz Difusa
float xL = 50.0, yL = 100.0;           // coordenadas da fonte luminosa
int   CRL = 255, CGL = 255, CBL = 255; // componentes da fonte luminosa
float xF = 0.0, yF = 0.0;              // coordenadas da face 
float Kd = 1.0; // coeficiente de reflexão difusa
float Ka = 1.0; // coeficiente de reflexão ambiente

void setup(){
  size(400,400);
  stroke(128);
  rectMode(CENTER);
}

float distancia(float xL, float YL, float xF, float yF){
  return sqrt(pow((xF-xL),2)+pow((yF-yL),2));  
}

float anguloIncidencia(float xL, float YL, float xF, float yF){
  return atan(abs(xF-xL)/abs(yF-yL));
}

float calcRaioRef(){
  return ((Ia * Ka + Id * Kd * cos(anguloIncidencia(xL,yL,xF,yF))) /2) * (100/distancia(xL,yL,xF,yF));
}

void draw(){ 
  background(0);
  translate(width/2, height/2);
  
  fill(CRL*calcRaioRef(), CGL*calcRaioRef(),CBL*calcRaioRef());
  noStroke();
  rect(0, 0, 100,100);
  
  fill(255,255,0);  
  stroke(255,255,0);
  ellipse(-xL,-yL,15,15);       // fonte luminosa
  line(-xL,-yL,0,0);            // raio incidente
  stroke(255);
  line(-width/2, 0, width, 0);  // plano
  line(0,0,0,-height/2);        // normal ao plano
  
  println(distancia(xL,yL,xF,yF));
  
}

void keyPressed(){
  if (keyPressed) { 
    if (key == CODED) { 
      if (keyCode == UP)    yL++; 
      if (keyCode == DOWN)  yL--;
      if (keyCode == RIGHT) xL--;
      if (keyCode == LEFT)  xL++;
    }
  }  
}
