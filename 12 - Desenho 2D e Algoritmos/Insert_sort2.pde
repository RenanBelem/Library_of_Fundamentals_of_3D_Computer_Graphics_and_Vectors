int [][] lista;

void insertSort2 (int [][]array, int tam, int c)
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
  noLoop();
  lista = new int [10][3]; // 10 linhas e 3 colunas
  
  lista[0][0] = 9;    // linha 0 coluna 0
  lista[0][1] = 100;  // linha 0 coluna 1
  lista[0][2] = 50;   // linha 0 coluna 2
  
  lista[1][0] = 8;    // linha 1 coluna 0
  lista[1][1] = 101;  // linha 1 coluna 1
  lista[1][2] = 51;   // linha 1 coluna 2
  
  lista[2][0] = 7;
  lista[2][1] = 102;
  lista[2][2] = 52;
  
  lista[3][0] = 6;
  lista[3][1] = 103;
  lista[3][2] = 53;
  
  lista[4][0] = 5;
  lista[4][1] = 104; 
  lista[4][2] = 54;
  
  lista[5][0] = 4;
  lista[5][1] = 105;  
  lista[5][2] = 55;
  
  lista[6][0] = 3;
  lista[6][1] = 106;
  lista[6][2] = 56;
  
  lista[7][0] = 2;
  lista[7][1] = 107; 
  lista[7][2] = 57;
  
  lista[8][0] = 1;
  lista[8][1] = 108; 
  lista[8][2] = 58;
  
  lista[9][0] = 0;
  lista[9][1] = 109;
  lista[9][2] = 59;
}

void draw(){
  int colOrdem = 2;
  println("Ordenando pela coluna "+colOrdem);
  insertSort2 (lista, 10, colOrdem);
  
  for(int i = 0; i< 10; i++){
    println(i+":  "+lista[i][0]+"-"+lista[i][1]+"-"+lista[i][2]);
  }
}
