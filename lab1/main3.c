#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2){

  double dist = sqrt(pow(x1-x2, 2.0) + pow(y1 -y2, 2.0));

  return dist;

}

int main(){
  double triangleCords[3][2];
  double a, b, c, s, area, perimeter;

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
  
  printf("area of triangle: %lf\n", area);
  printf("perimeter of triangle: %lf\n", perimeter);

    return 0;
}

