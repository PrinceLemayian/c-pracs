#include <stdio.h>

int main() {
  int count = 0;
  int num = 1;

  while (count < 20) {
    if (num % 3 == 0) {
      printf("%d\n", num);
      count++;
    }
    num++;
  }
  return 0;
}
