#include <stdio.h>

int main() {
  int number;
  float price;

  printf("Enter an integer: ");
  scanf("%d", &number);

  printf("Enter a price: ");
  scanf("%f", &price);

  printf("You entered: %d and %.2f\n", number, price);
  return 0;
}
