#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void printArray(double arr[], int N);
void readArray(double arr[], int N);
double L2(double arr[], int N);
void getArrays(double * Z[], int size);
void printArrays(double * Z[], int size);

int main (){
  int size, isSorted, solving;
  char input[64];
  char * endptr;
  char * piece;

  printf("Give size of array [0-32]: ");
  fgets(input, sizeof(input), stdin);                             

  input[strcspn(input, "\n")] = '\0';                             
  piece = strtok(input, " ");           
  size = atoi(piece);

  double A[size];
  double B[size];
  double C[size];

  double *Z[] = { A, B, C};

  getArrays(Z, size);

  printArrays(Z, size);

  isSorted = 0;
  solving = 0;
  double * tempZ[3] = {Z[0], Z[1], Z[2]};
  while(!isSorted){

    for(int i = 1; i < size; i++){
      double L2_1 = L2(Z[i-1], size);
      double L2_2 = L2(Z[i], size);
      if(L2_1 >= L2_2){
        solving += 1;
        continue;

      }else {
        tempZ[i-1] = Z[i];
        tempZ[i] = Z[i-1];

        Z[0] = tempZ[0];
        Z[1] = tempZ[1];
        Z[2] = tempZ[2];
      }
    }

    
    if(solving == size -1){
      isSorted = 1;
      break;

    }else{
      solving = 0;

    }
  }

  printf("After sorting:\n");
  printArrays(Z, size);

  printf("\n"); 

  if(
  Z[0][1] == Z[1][0] &&
  Z[0][2] == Z[2][0] &&
  Z[1][2] == Z[2][1]
  ){

    printf("Z is symetric\n");

  }else{
    printf("Z is not symetric\n");

  }

  return 0;

}

void printArray(double arr[], int N){
    
  for(int i = 0; i < N; i++){
    printf("%lf ", arr[i]);

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

double L2(double arr[], int N){

  double L2Norm = 0;

  for(int i = 0; i < N; i++){
    L2Norm += pow(arr[i], 2.0);

  }

  return sqrt(L2Norm);
}

void getArrays(double *Z[], int size){
  char * piece;
  char * endptr;
  char input[64];
  for(int i = 0; i < 3; i++){
    
    printf("Input %d values: ", size);
    fgets(input, sizeof(input), stdin);                             

    input[strcspn(input, "\n")] = '\0';                             
    piece = strtok(input, " ");           
    Z[i][0] = strtod(piece, &endptr);

    for(int i2 = 1; i2 < size; i2++){
    piece = strtok(NULL, " ");           
    Z[i][i2] = strtod(piece, &endptr);

    }
  }
}

void printArrays(double * Z[], int size){
  for(int i = 0; i < 3; i++){
    printf("Values : ");
    printArray(Z[i], size);
    printf(" %lf\n", L2(Z[i], size));
    
  }
}











