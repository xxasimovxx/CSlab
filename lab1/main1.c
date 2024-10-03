#include <stdio.h>
#include <math.h>

int main(){
  double a,b,outA,outB;  

  printf("Input first number:\n");
  scanf("%lf", &a);

  printf("Input second number:\n");
  scanf("%lf", &b);

  printf("%.1lf\n", a * b);
  printf("%0.2E\n", a / b);
  printf("|%.2lf | %.2lf|\n", sqrt(a), sqrt(b));
  printf("%lf   %lf\n", pow(a, (1/3.0)), pow(b, (1/3.0)));
  printf("%.0lf %.0lf\n", pow(a, 4), pow(b, 4));
  printf("%lf %lf\n", sin(a), cos(b));
    
    return 0;
}
