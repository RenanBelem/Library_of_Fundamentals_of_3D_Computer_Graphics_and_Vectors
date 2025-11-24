int [] lista = {9,8,7,6,5,4,3,2,1,0};

void insertSort (int []vet, int tam)
{
  for(int i=0; i<tam; ++i){
   int j = i;
   while(j>0 && vet[j-1]>vet[j]){
    int tmp = vet[j];
    vet[j] = vet[j-1];
    vet[j-1] = tmp;
    j = j - 1;
   }
  }
}

void setup(){
  noLoop();
}

void draw(){
  insertSort(lista,10);
  println(lista);
}
