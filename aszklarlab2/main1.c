#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(double arr[], int N);
void readArray(double arr[], int N);
void getArrays(double Z[], int size);

int main (){
  int size;

  printf("Give size of array [0-32]: ");
  scanf("%d", &size);
  getchar();

  if(size > 32){

    puts("Wrong value");
    return -1;
  }

  double Z[size];

  getArrays(Z, size);
  
  printArray(Z, size);

  return 0;

}

void printArray(double arr[], int N){
    
  for(int i = 0; i < N; i++){
    printf("%lf\n", arr[i]);

  }
}

void readArray(double arr[], int N){
  
  double A[N];
    
  for(int i = 0; i < N; i++){
    A[i] = arr[i];

  }

  for(int i = 0; i < N; i++){
    printArray(A, N);

  }
}

void getArrays(double Z[], int size){
  char * piece;
  char * endptr;
  char input[100];
    
  printf("Input %d values: ", size);
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';                             
  printf("%s", input);
  piece = strtok(input, " ");           
  Z[0] = strtod(piece, &endptr);

  for(int i = 1; i < size; i++){
    piece = strtok(NULL, " ");           
    Z[i] = strtod(piece, &endptr);
    
  } 
}










