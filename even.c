#include <stdio.h>

int main() {
  printf("Even numbers from 1 to 20:\n");
  for (int i = 2; i <= 20; i += 2) {
    printf("%d\n", i);
  }
  return 0;
}
