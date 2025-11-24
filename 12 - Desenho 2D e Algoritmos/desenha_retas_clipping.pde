float [][]ponto; // matriz de pontos: linha = id do ponto, coluna 0 = x e 1 = y
int nPontos = 12;  // número de pontos considerados

float [][]reta;
int nRetas = nPontos/2;

float [][]retaProcessada;

int INSIDE_  = 0; // 0000
int LEFT_    = 1; // 0001
int RIGHT_   = 2; // 0010
int BOTTOM_  = 4; // 0100
int TOP_     = 8; // 1000

float x_max = 600;
float y_max = 400;
float x_min = 100;
float y_min = 100;

void setup(){
 size(700,500); 
 ponto = new float[nPontos][2];  // [2] indica x e y ou seja [0]=x e [1]=y
 reta  = new float [nRetas][4];  // [4] indica Pix, Piy, Pfx, Pfy (início e final da reta)
 retaProcessada = new float [nRetas][4]; // retas processadas/recortadas
 noLoop();
}

int computeCode(float x, float y){
   int code = INSIDE_;  
   if (x < x_min) code = LEFT_;
   if (x > x_max) code = RIGHT_;
   if (y < y_min) code = BOTTOM_;
   if (y > y_max) code = TOP_; 
   return code;
}

float[] cohenSutherlandClip( float x1, float y1, float x2, float y2){
  
float ret[] = new float[4]; // para o retorno dos pontos processados
  
int code1 = computeCode(x1, y1);
int code2 = computeCode(x2, y2);
 
boolean accept = false;
 
while(true) {
      if ((code1 == 0) && (code2 == 0)) {
          // If both endpoints lie within rectangle
          accept = true;
          break;
      }
      else if (code1 == code2) {
          // If both endpoints are outside rectangle,
          // in same region
          break;
      }
      else {
          // Some segment of line lies within the
          // rectangle
          int code_out;
          float x=0, y=0;
          // At least one endpoint is outside the
          // rectangle, pick it.
          if (code1 != 0)
              code_out = code1;
          else
              code_out = code2;
          // Find intersection point;
          // using formulas y = y1 + slope * (x - x1),
          // x = x1 + (1 / slope) * (y - y1)
          if (code_out == TOP_) {
              // point is above the clip rectangle
              x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
              y = y_max;
          }
          else if (code_out == BOTTOM_) {
              // point is below the rectangle
              x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
              y = y_min;
          }
          else if (code_out == RIGHT_) {
              // point is to the right of rectangle
              y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
              x = x_max;
          }
          else if (code_out == LEFT_) {
              // point is to the left of rectangle
              y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
              x = x_min;
          }
          // Now intersection point x, y is found
          // We replace point outside rectangle
          // by intersection point
          if (code_out == code1) {
              x1 = x;
              y1 = y;
              code1 = computeCode(x1, y1);
          }
          else {
              x2 = x;
              y2 = y;
              code2 = computeCode(x2, y2);
          }
      }
  }
  if (accept) {
      println( "Line accepted from " + x1 + ", " + y1 + " to " + x2 + ", " + y2);
      ret[0] = x1; ret[1] = y1; ret[2] = x2; ret[3] = y2; // artifício para retorno de múltiplos valores
  }
  else {
      println( "Line rejected");
      ret[0] = 0; ret[1] = 0; ret[2] = 0; ret[3] = 0; // linha rejeitada, valores zerados
  }
  return ret;
}

// inicialização de valores para sequência de retas interligadas
void inicializaPontos(){ 
  ponto[0][0] = 110; // P0x - reta 0 ponto inicial
  ponto[0][1] = 220; // P0y - reta 0 ponto inicial
  ponto[1][0] = 500; // P1x - reta 0 ponto final
  ponto[1][1] = 350; // P1y - reta 0 ponto final
  ponto[2][0] = 300; // P2x - reta 1 ponto inicial
  ponto[2][1] = 300; // P2y - reta 1 ponto inicial
  ponto[3][0] = 550; // P3x - reta 1 ponto final
  ponto[3][1] =  50; // P3y - reta 1 ponto final 
  ponto[4][0] = 350;
  ponto[4][1] = 220;
  ponto[5][0] = 650;
  ponto[5][1] = 220; 
  ponto[6][0] =  50;
  ponto[6][1] = 120;
  ponto[7][0] = 300;
  ponto[7][1] = 120;
  ponto[8][0] = 220;
  ponto[8][1] =  50;
  ponto[9][0] = 220;
  ponto[9][1] = 450;
  ponto[10][0] = 50;
  ponto[10][1] = 250;
  ponto[11][0] = 150;
  ponto[11][1] = 450; 
}

void inicializaRetas(){
  int j = 0; 
  for(int i=0; i<nRetas; i++){
    reta[i][0] = ponto[j][0];
    reta[i][1] = ponto[j][1];
    reta[i][2] = ponto[j+1][0];
    reta[i][3] = ponto[j+1][1];  
    j = j + 2;  
  } 
}

void recortaRetas(){
  float retaR[] = new float[4];
  
  for(int i=0; i<nRetas; i++){  
    retaR = cohenSutherlandClip(reta[i][0], reta[i][1], reta[i][2], reta[i][3]);
    retaProcessada[i][0] = retaR[0];
    retaProcessada[i][1] = retaR[1];
    retaProcessada[i][2] = retaR[2];
    retaProcessada[i][3] = retaR[3];    
  }
}

void desenhaRetas(){  
  strokeWeight(2);
  for(int i=0; i<nRetas; i++){
    color cor = color(random(100, 255),random(100, 255),random(100, 255)); // criação de uma cor aleatória clara
    stroke(cor); // cor do traço
    fill(cor);   // cor do texto
    line(reta[i][0],height-reta[i][1], reta[i][2],height-reta[i][3]);
    text("Reta"+i, (reta[i][0]+reta[i][2])/2, (height-reta[i][1]+height-reta[i][3])/2);
  }
}

void desenhaRetasProcessadas(){  
  strokeWeight(4);
  for(int i=0; i<nRetas; i++){
    color cor = color(random(100, 255),random(100, 255),random(100, 255)); // criação de uma cor aleatória clara
    stroke(cor); // cor do traço
    fill(cor);   // cor do texto
    line(retaProcessada[i][0],height-retaProcessada[i][1], retaProcessada[i][2],height-retaProcessada[i][3]);
    text("RetaR"+i, (retaProcessada[i][0]+retaProcessada[i][2])/2, (height-retaProcessada[i][1]+height-retaProcessada[i][3])/2);
  }
}

void draw(){
  background(0);
  // Desenho do Clipping Frame
  strokeWeight(1);
  stroke(128);
  line(0, y_max, width, y_max);
  line(0, y_min, width, y_min);
  line(x_min, 0, x_min, height);
  line(x_max, 0, x_max, height);
  
  inicializaPontos();
  inicializaRetas();
//  desenhaRetas();
  recortaRetas();
  desenhaRetasProcessadas();

}
