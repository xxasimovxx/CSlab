#include <stdio.h>

int main(){
  int patternSize;
  
  printf("Enter pattern size:\n");
  scanf("%d", &patternSize);
  printf("\n");

  int rowMaxSize = patternSize * 2 -1;
  int starAmount = 1;
  int spaceAmount = rowMaxSize - starAmount;

  for(int i = 0; i < rowMaxSize; i++){

    for(int spaces = 0; spaces < spaceAmount/2; spaces++){
      
        printf(" "); 
    }
    for(int stars = 0; stars < starAmount; stars++){

        printf("*"); 
    }
    for(int spaces = 0; spaces < spaceAmount/2; spaces++){

        printf(" "); 
    }

    if(i < rowMaxSize/2){

      starAmount += 2;
      spaceAmount = rowMaxSize - starAmount;
    } else {

    spaceAmount += 2;
      starAmount = rowMaxSize - spaceAmount;
    }

    printf("\n");
    
    }

  
  return 0;
}
