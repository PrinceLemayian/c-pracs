#include <stdio.h>

#define PI 3.14159

int main() {
  double radius, volume;

  printf("Enter the radius of the sphere: ");
  scanf("%lf", &radius);

  volume = (4.0 / 3.0) * PI * radius * radius * radius;
  printf("Volume = %.2f\n", volume);
  printf("Item\tunit\tPurchase\n\tPrice\tDate\n");

  return 0;
}
