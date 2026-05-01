#include <stdio.h>

int main() {
  int numbers[5] = {10, 20, 30, 40, 50};
  int i, sum = 0;
  float average;

  // Loop through the array and calculate sum
  for (i = 0; i < 5; i++) {
    sum += numbers[i];
  }

  // Calculate average
  average = sum / 5.0;

  // Print results
  printf("Sum = %d\n", sum);
  printf("Average = %.2f\n", average);

  return 0;
}
