#include <stdio.h>

int main(){
  int a, b;
  
  printf("Enter first number:\n");
  scanf("%d", &a);
  printf("Enter second number:\n");
  scanf("%d", &b);

  while(a != b){

    if(a > b){
      a -= b;

    } else {
      b -= a;
    }
  }

  printf("HCF is equal to : %d\n", a);

  return 0;
}
