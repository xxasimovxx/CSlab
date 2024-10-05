#include <stdio.h>
#include <math.h>

void printArray(double arr[], int N);
void readArray(double arr[], int N);
double L2(double arr[], int N);
int main (){

  double arr[] = {1.0,2.0,3.0};
  
  printArray(arr, 2);

  printf("%lf\n", L2(arr, 2));


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

double L2(double arr[], int N){

  double L2Norm = 0;

  for(int i = 0; i < N; i++){
    L2Norm += pow(arr[i], 2.0);

  }

  return sqrt(L2Norm);
}










