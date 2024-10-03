#include <stdio.h>

int main(){

  float a, b;
  a = 1000000000;
  b = 1000000001;
  
  float w1 = a * a - b * b;
  float w2 = (a + b) * (a - b);

  printf(" w1 = %f w2 = %f\n", w1, w2 );
  //i think that this strange behaviour is because variable overflows, data is to big to fit in

  return 0;
}
