int [][] ponto;  // matriz de pontos: linha = id do ponto, coluna 0 = x, 1 = y e 2 = z
int nPontos = 12;  // número de pontos considerados

int [][] triangulo;
int nTriangulos = nPontos/3;

int [][] lista;

void insertSort(int [][]array, int tam, int c)
{
  int tmp, j;
  for(int i=0; i<tam; ++i){
     tmp = array[i][c];
     int[] tmpRow = array[i];
     j = i - 1;
     while (( j>= 0) && (array[j][c] > tmp)){
       array[j+1] = array[j];
       j = j -1;
     }
     array[j+1] = tmpRow;
   }
}

void setup(){
 size(700,500); 
 ponto = new int[nPontos][3];                     // [3] indica x, y e z ou seja [0]=x, [1]=y e [2]=z
 triangulo  = new int [nTriangulos][9];           // [9] indica P0x, P0y, P0x, P1x, P1y, P1z, P2x, P2y, P2z
 noLoop();
}

void inicializaPontos(){ 
  ponto[0][0] = 250; // P0x - triângulo 0 
  ponto[0][1] = 250; // P0y - triângulo 0
  ponto[0][2] =  10; // P0z - triângulo 0 
  ponto[1][0] = 350; // P1x - triângulo 0
  ponto[1][1] = 250; // P1y - triângulo 0
  ponto[1][2] =  10; // P1z - triângulo 0 
  ponto[2][0] = 300; // P2x - triângulo 0
  ponto[2][1] = 320; // P2y - triângulo 0
  ponto[2][2] =  10; // P2z - triângulo 0 
  
  ponto[3][0] = 300; // P0x - triângulo 1
  ponto[3][1] = 200; // P0y - triângulo 1
  ponto[3][2] =   0; // P0z - triângulo 1 
  ponto[4][0] = 400; // P1x - triângulo 1
  ponto[4][1] = 200; // P1y - triângulo 1
  ponto[4][2] =   0; // P1z - triângulo 1 
  ponto[5][0] = 350; // P2x - triângulo 1
  ponto[5][1] = 300; // P2y - triângulo 1
  ponto[5][2] =   0; // P2z - triângulo 1 
  
  ponto[6][0] = 100; // P0x - triângulo 2
  ponto[6][1] = 350; // P0y - triângulo 2
  ponto[6][2] =  30; // P0z - triângulo 2 
  ponto[7][0] = 250; // P1x - triângulo 2
  ponto[7][1] = 325; // P1y - triângulo 2
  ponto[7][2] =  30; // P1z - triângulo 2 
  ponto[8][0] = 250; // P2x - triângulo 2
  ponto[8][1] = 400; // P2y - triângulo 2
  ponto[8][2] =  30; // P2z - triângulo 2 
  
  ponto[9][0]  = 200; // P0x - triângulo 3
  ponto[9][1]  = 300; // P0y - triângulo 3
  ponto[9][2]  =  20; // P0z - triângulo 3 
  ponto[10][0] = 300; // P1x - triângulo 3
  ponto[10][1] = 300; // P1y - triângulo 3
  ponto[10][2] =  20; // P1z - triângulo 3 
  ponto[11][0] = 270; // P2x - triângulo 3
  ponto[11][1] = 370; // P2y - triângulo 3
  ponto[11][2] =  20; // P2z - triângulo 3 
}

void inicializaTriangulos(){
  triangulo[0][0] = ponto[0][0]; // P0x
  triangulo[0][1] = ponto[0][1]; // P0y
  triangulo[0][2] = ponto[0][2]; // P0z
  triangulo[0][3] = ponto[1][0]; // P1x
  triangulo[0][4] = ponto[1][1]; // P1y
  triangulo[0][5] = ponto[1][2]; // P1z
  triangulo[0][6] = ponto[2][0]; // P2x
  triangulo[0][7] = ponto[2][1]; // P2y
  triangulo[0][8] = ponto[2][2]; // P2z
  
  triangulo[1][0] = ponto[3][0]; 
  triangulo[1][1] = ponto[3][1];  
  triangulo[1][2] = ponto[3][2];
  triangulo[1][3] = ponto[4][0];
  triangulo[1][4] = ponto[4][1];
  triangulo[1][5] = ponto[4][2];
  triangulo[1][6] = ponto[5][0];
  triangulo[1][7] = ponto[5][1];  
  triangulo[1][8] = ponto[5][2];
  
  triangulo[2][0] = ponto[6][0]; 
  triangulo[2][1] = ponto[6][1];  
  triangulo[2][2] = ponto[6][2];
  triangulo[2][3] = ponto[7][0];
  triangulo[2][4] = ponto[7][1];
  triangulo[2][5] = ponto[7][2];
  triangulo[2][6] = ponto[8][0];
  triangulo[2][7] = ponto[8][1];  
  triangulo[2][8] = ponto[8][2];
     
  triangulo[3][0] = ponto[9][0]; 
  triangulo[3][1] = ponto[9][1];  
  triangulo[3][2] = ponto[9][2];
  triangulo[3][3] = ponto[10][0];
  triangulo[3][4] = ponto[10][1];
  triangulo[3][5] = ponto[10][2];
  triangulo[3][6] = ponto[11][0];
  triangulo[3][7] = ponto[11][1];  
  triangulo[3][8] = ponto[11][2];
}

void inicializaTriangulos2(){ // função alternativa
  int j = 0;
  for(int i=0; i<nTriangulos; i++){
    triangulo[i][0] = ponto[j][0];   // P0x
    triangulo[i][1] = ponto[j][1];   // P0y
    triangulo[i][2] = ponto[j][2];   // P0z
    triangulo[i][3] = ponto[j+1][0]; // P1x
    triangulo[i][4] = ponto[j+1][1]; // P1y
    triangulo[i][5] = ponto[j+1][2]; // P1z
    triangulo[i][6] = ponto[j+2][0]; // P2x
    triangulo[i][7] = ponto[j+2][1]; // P2y
    triangulo[i][8] = ponto[j+2][2]; // p2z
    j=j+3;
  }
}

void desenhaTriangulos(){  
  for(int i=0; i<nTriangulos; i++){
    color cor = color(random(50, 128),random(50, 128),random(50, 128)); // criação de uma cor aleatória escura
    fill(cor);   // cor do triangulo
    triangle(triangulo[i][0], height-triangulo[i][1], triangulo[i][3], height-triangulo[i][4], triangulo[i][6], height-triangulo[i][7]);
    fill(255);   // cor do texto
    text("Tri."+i, (triangulo[i][0]+triangulo[i][3]+triangulo[i][6])/3, height-(triangulo[i][1]+triangulo[i][4]+triangulo[i][7])/3);
  }
}

void draw(){
  background(0);
  
  inicializaPontos();
  inicializaTriangulos2();
  insertSort(triangulo, nTriangulos, 4); 
  desenhaTriangulos();
}
