#include <stdio.h>

int main() {
  int num1 = 1;
  int num2 = 10;
  int num3 = -100;

  //(%3d) specifies minimum number of characters to print is 3
  printf("%3d\n", num1);
  printf("%3d\n", num2);
  printf("%3d\n", num3);

  // specify 0s instead of blank spaces
  printf("%04d\n", num1);
  printf("%04d\n", num2);
  printf("%04d\n", num3);

  // specify sign of numbers
  printf("%d\n", num1);
  printf("%d\n", num2);
  printf("%d\n", num3);

  // precision
  float price1 = 19.99;
  float price2 = 1.50;
  float price3 = -100.00;

  // (.2f - display 2 digits after the decimal)
  // mixing width + sign + precision format specifiers
  printf("%+7.2f\n", price1);
  printf("%+7.2f\n", price2);
  printf("%+7.2f\n", price3);

  return 0;
}
