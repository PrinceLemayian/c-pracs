#include <stdio.h>

int main() {
  int choice;

  printf("=== Simple Calculator ===\n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("Enter your choice (1-4): ");
  scanf("%d", &choice);

  int a, b;

  switch (choice) {
  case 1:
    printf("Enter two numbers (a, b): ");
    scanf("%d, %d", &a, &b);
    printf("Result = %d\n", a + b);
    break;

  case 2:
    printf("Enter two numbers (a, b): ");
    scanf("%d, %d", &a, &b);
    printf("Result = %d\n", a - b);
    break;

  case 3:
    printf("Enter two numbers (a, b): ");
    scanf("%d, %d", &a, &b);
    printf("Result = %d\n", a * b);
    break;

  case 4:
    printf("Enter two numbers (a, b): ");
    scanf("%d, %d", &a, &b);

    if (b != 0)
      printf("Result = %d\n", a / b);
    else
      printf("Cannot divide by zero!\n");

    break;

  default:
    printf("Invalid choice!\n");
  }

  return 0;
}
