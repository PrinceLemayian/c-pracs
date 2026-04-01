#include <stdio.h>

int main() {
  int a = 20, b = 6;

  printf("=== Arithmetic Operators in C ===\n\n");
  printf("a = %d, b = %d\n\n", a, b);

  printf("Addition       : a + b = %d\n", a + b);
  printf("Subtraction    : a - b = %d\n", a - b);
  printf("Multiplication : a * b = %d\n", a * b);
  printf("Division       : a / b = %d\n", a / b);
  printf("Modulus        : a %% b = %d\n", a % b);

  printf("\n--- Increment & Decrement ---\n");
  int x = 5;
  printf("x = %d\n", x);
  printf("x++ (post) = %d  → x is now %d\n", x++, x);
  printf("++x (pre)  = %d\n", ++x);
  printf("x-- (post) = %d  → x is now %d\n", x--, x);
  printf("--x (pre)  = %d\n", --x);

  printf("\n--- Integer vs Float Division ---\n");
  int int_div = 7 / 2;
  float float_div = 7.0 / 2;
  printf("7 / 2   (int)   = %d  ← truncates decimal\n", int_div);
  printf("7.0 / 2 (float) = %.1f\n", float_div);

  return 0;
}
