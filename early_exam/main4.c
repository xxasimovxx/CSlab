#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct IS{
  int size;
  int * ptr;

}IntSequence;

IntSequence triangular_numbers(int n);

int main(void){
  int n = 35;
  IntSequence asd = triangular_numbers(n);
  for(int i = 0 ; i < asd.size; i++){
    printf("%d, ", asd.ptr[i]);

  }

  free(asd.ptr);

  return 0;

}

IntSequence triangular_numbers(int n){
  IntSequence triangles;
  int elementsAmount = (1 + sqrt(1 + 8*n))/2 - 1;


  int *ptr = (int*)malloc(elementsAmount * sizeof(int));
  


  if( ptr == NULL){
    IntSequence seq = {0, NULL};
      return seq;

  }
  int i = 1;


  while(i-1 < elementsAmount){ 
    ptr[i-1] = ((i + 1)*i)/2; 

    i++;

    }

  


  triangles.size = elementsAmount;
  triangles.ptr = ptr;
  
  return triangles;

}
