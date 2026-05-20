// Computes the dimensional weight of a box
// from input provided by the user

#include <stdio.h>
// macro definition
#define CUBIC_IN_PER_LB 166

int main() {
  int height, length, width, volume, weight;

  printf("Enter height of a box: ");
  scanf("%d", &height);
  printf("Enter length of a box: ");
  scanf("%d", &length);
  printf("Enter width of a box: ");
  scanf("%d", &width);
  volume = height * length * width;
  weight = (volume + CUBIC_IN_PER_LB - 1) / CUBIC_IN_PER_LB;

  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", weight);

  return 0;
}
