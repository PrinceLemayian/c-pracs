#include <stdio.h>
#define LENGTH 4

void times_two(int *a, int len) {
  for (int i = 0; i < len; i++) {
    a[i] *= 2;
  }

  // return *a;
}

int main(void) {
  int arr[LENGTH] = {1, 2, 3, 4};

  times_two(arr, LENGTH);

  for (int i = 0; i < LENGTH; i++) {
    printf("%d, ", arr[i]);
  }

  return 0;
}
