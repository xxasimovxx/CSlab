#include <stdio.h>
#include <math.h>

#define PI (4.*atan(1)) // normal one
#define PIa 4.*atan(1) // without brackets
#define PIb 4*atan(1) // without dot at 4

int main(){

  printf("%lf\n", 3 / PI );   // 0.954930
  printf("%lf\n", 3 / PIa );  // 0.589049
  printf("%lf\n", 3 / PIb );  // 0.000000
// Preprocessor is just doing simple "find & replace", so this code:

// 1) 3 / (4.*atan(1))
// 2) 3 / 4.*atan(1) so this is 1.33 * atan(1);
// 3) 3/4 * atan(1) so this is 1 * atan(1) and i am not sure why
// i am not sure if this is correct whay of thinking but i will go depper into topic in free time

  return 0;
}
