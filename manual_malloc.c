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
  for (int i = 0; i < 5; i++) {
    numbers[i] = (i + 1) * 10;
  }

  // Print the values
  for (int i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
  }

  // Give the memory back to the system
  free(numbers);

  return 0;
}
