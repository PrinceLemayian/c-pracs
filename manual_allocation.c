#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *numbers;

  // Allocate memory for 5 integers
  numbers = malloc(5 * sizeof(int));

  if (numbers == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  // Use the allocated memory
  numbers[0] = 10;
  numbers[1] = 20;
  numbers[2] = 30;
  numbers[3] = 40;
  numbers[4] = 50;

  for (int i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
  }

  // Give the memory back
  free(numbers);

  return 0;
}
