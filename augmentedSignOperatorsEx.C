#include <stdio.h>

int main() {
  int a = 10, b = 5;

  printf("Initial values:\n");
  printf("a = %d, b = %d\n\n", a, b);

  // Addition assignment
  a += b;
  printf("After a += b, a = %d\n", a);

  // Subtraction assignment
  a -= b;
  printf("After a -= b, a = %d\n", a);

  // Multiplication assignment
  a *= b;
  printf("After a *= b, a = %d\n", a);

  // Division assignment
  a /= b;
  printf("After a /= b, a = %d\n", a);

  // Modulus assignment
  a %= b;
  printf("After a %%= b, a = %d\n", a);

  return 0;
}
