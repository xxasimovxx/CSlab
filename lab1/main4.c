#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PI (4.*atan(1))

double distance(double x1, double y1, double x2, double y2){

  double dist = sqrt(pow(x1-x2, 2.0) + pow(y1 -y2, 2.0));

  return dist;

}

int main(){
  double triangleCords[3][2];
  double a, b, c, s, area, perimeter, alfa, beta, gamma;
  bool isEqualPi = false;

  printf("Input first x coordinate:\n");
  scanf("%lf", &triangleCords[0][0]);
  printf("Input first y coordinate:\n");
  scanf("%lf", &triangleCords[0][1]);

  printf("Input second x coordinate:\n");
  scanf("%lf", &triangleCords[1][0]);
  printf("Input second y coordinate:\n");
  scanf("%lf", &triangleCords[1][1]);


  printf("Input third x coordinate:\n");
  scanf("%lf", &triangleCords[2][0]);
  printf("Input third y coordinate:\n");
  scanf("%lf", &triangleCords[2][1]);

  a = distance(triangleCords[0][0],triangleCords[0][1],triangleCords[1][0],triangleCords[1][1]);

  b = distance(triangleCords[0][0],triangleCords[0][1],triangleCords[2][0],triangleCords[2][1]);

  c = distance(triangleCords[1][0],triangleCords[1][1],triangleCords[2][0],triangleCords[2][1]);

  perimeter = a + b + c;

  s = 0.5 * perimeter;

  area = sqrt(s*(s-a)*(s-b)*(s-c));

  alfa = (atan(sqrt((s-a)*(s-b)/(s*(s-c)))) * 180.0 * 2.0)/ PI;
  beta = (atan(sqrt((s-a)*(s-c)/(s*(s-b)))) * 180.0 * 2.0)/ PI;
  gamma = (atan(sqrt((s-b)*(s-c)/(s*(s-a))))* 180.0 * 2.0)/ PI;

  if((alfa + beta + gamma) == 180.0){isEqualPi = true;};
  
  printf("area of triangle: %lf\n", area);
  printf("perimeter of triangle: %lf\n", perimeter);

  printf("alfa: %lf\n", alfa);
  printf("beta: %lf\n", beta);
  printf("gamma: %lf\n", gamma);

  printf("Angles are equal pi: %s\n", isEqualPi ? "true" : "false");

  

    return 0;
}

