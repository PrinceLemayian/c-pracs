#include <stdio.h>

int main() {
  int scores[] = {45, 78, 92, 67, 88};
  int *highest = &scores[0];

  for (int i = 1; i < 5; i++) {
    if (scores[i] > *highest) {
      highest = &scores[i];
    }
  }

  printf("Highest score: %d\n", *highest);
  printf("Memory address: %p\n", (void *)highest);

  return 0;
}
