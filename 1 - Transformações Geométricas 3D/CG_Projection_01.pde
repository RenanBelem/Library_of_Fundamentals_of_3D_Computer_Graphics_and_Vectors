// Objeto 3D - Paraleleípedo
float[] V1 = {10,10,10,1};
float[] V2 = {100,10,10,1};
float[] V3 = {100,10,10,1};
float[] V4 = {10,100,10,1};
float[] V5 = {100,10,100,1};
float[] V6 = {10,10,100,1};
float[] V7 = {10,100,100,1};
float[] V8 = {100,100,100,1};

// Multiplicação de vetor (vértice) por Matriz
float[] multVxMT(float[] Vin, float[][] M) {
  float[] Vout = new float[4];
  Vout[0] = Vin[0]*M[0][0] + Vin[1]*M[1][0] + Vin[2]*M[2][0] + Vin[3]*M[3][0];
  Vout[1] = Vin[0]*M[0][1] + Vin[1]*M[1][1] + Vin[2]*M[2][1] + Vin[3]*M[3][1];
  Vout[2] = Vin[0]*M[0][2] + Vin[1]*M[1][2] + Vin[2]*M[2][2] + Vin[3]*M[3][2];
  Vout[3] = Vin[0]*M[0][3] + Vin[1]*M[1][3] + Vin[2]*M[2][3] + Vin[3]*M[3][3]; 
  return Vout;
}

// Multiplicação de 2 matrizes 4x4
float[][] multM(float[][]M1, float[][]M2){
  float somaprod = 0;
  float[][] Mout = new float[4][4];
  for(int linha=0; linha<4; linha++){
    for(int coluna=0; coluna<4; coluna++){
      somaprod=0;
      for(int i=0; i<4; i++) {somaprod+=M1[linha][i]*M2[i][coluna];}
      Mout[linha][coluna]=somaprod;
    }
  }
  return Mout;
}

/////////////////////////////////////////// Matrizes de Transformação de Visualização
float Xo = 25; // posição do Observador
float Yo = 35;
float Zo = 45;

float[][] MT1 = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {Xo,Yo,Zo,1}};
float[][] MT2 = {{1,0,0,0}, {0,cos(PI/4),-sin(PI/4),0}, {0,sin(PI/4),cos(PI/4),0}, {0,0,0,1}};
float[][] MT3 = {{cos(atan(Xo/Yo))+PI/2, 0, sin(atan(Xo/Yo))+PI/2, 0},
                {0,1,0,0},
                {-sin(atan(Xo/Yo))+PI/2, 0, cos(atan(Xo/Yo))+PI/2, 0},
                {0,0,0,1}};
float[][] MT4 = {{1,0,0,0}, 
                {0, cos(PI/4-atan(sqrt(sq(Xo)+sq(Yo))/Zo)), -sin(PI/4-atan(sqrt(sq(Xo)+sq(Yo))/Zo)), 0},
                {0, sin(PI/4-atan(sqrt(sq(Xo)+sq(Yo))/Zo)), cos(PI/4-atan(sqrt(sq(Xo)+sq(Yo))/Zo)), 0},
                {0,0,0,1}};
float[][] MT5 = {{1,0,0,0}, {0,1,0,0}, {0,0,-1,0}, {0,0,0,1}};
float[][] MTV = new float [4][4];
/////////////////////////////////////////////

// Matriz de Escala
float[][] MS = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

void setup() {
  size(700,600);
  
  MTV = multM(MT1, MT2);
  MTV = multM(MTV, MT3);
  MTV = multM(MTV, MT4);
  MTV = multM(MTV, MT5);  
  MTV = multM(MTV, MS);
  
  V1 = multVxMT(V1, MTV);
  V2 = multVxMT(V2, MTV);
  V3 = multVxMT(V3, MTV);
  V4 = multVxMT(V4, MTV);
  V5 = multVxMT(V5, MTV);  
  V6 = multVxMT(V6, MTV);
  V7 = multVxMT(V7, MTV);
  V8 = multVxMT(V8, MTV);
  
}

void draw() {
  
  line(V1[0],height-V1[1],V2[0],height-V2[1]);
  line(V2[0],height-V2[1],V3[0],height-V3[1]);
// line(V3[0],height-V3[1],V4[0],height-V4[1]);
// line(V4[0],height-V4[1],V1[0],height-V1[1]);
  
  line(V2[0],height-V2[1],V5[0],height-V5[1]);
// line(V5[0],height-V5[1],V8[0],height-V8[1]);
// line(V8[0],height-V8[1],V3[0],height-V3[1]);
//  ine(V3[0],height-V3[1],V2[0],height-V2[1]);
  
  line(V5[0],height-V5[1],V6[0],height-V6[1]);
  line(V6[0],height-V6[1],V7[0],height-V7[1]);
  line(V7[0],height-V7[1],V8[0],height-V8[1]);
  line(V8[0],height-V8[1],V5[0],height-V5[1]);
  
  line(V6[0],height-V6[1],V1[0],height-V1[1]);
  line(V1[0],height-V1[1],V4[0],height-V4[1]);
  line(V4[0],height-V4[1],V7[0],height-V7[1]);
  line(V7[0],height-V7[1],V6[0],height-V6[1]);
  
}
