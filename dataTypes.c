#include <stdio.h>

int main() {
  // Integer type
  int age = 18;

  // Floating-point types
  float height = 5.9f;
  double weight = 65.75;

  // Character type
  char grade = 'A';

  // Printing values
  printf("Integer (age): %d\n", age);
  printf("Float (height): %.2f\n", height);
  printf("Double (weight): %.2lf\n", weight);
  printf("Character (grade): %c\n", grade);

  // Showing size of each data type
  printf("\nSizes of data types (in bytes):\n");
  printf("int: %lu\n", sizeof(age));
  printf("float: %lu\n", sizeof(height));
  printf("double: %lu\n", sizeof(weight));
  printf("char: %lu\n", sizeof(grade));

  return 0;
}
