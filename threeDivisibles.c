#include <stdio.h>

int main() {
  int count = 0;
  int num = 1;

  printf("First 20 numbers divisible by 3:\n");
  while (count < 20) {
    if (num % 3 == 0) {
      printf("%d\n", num);
      count++;
    }
    num++;
  }
  return 0;
}
