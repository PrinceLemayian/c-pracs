#include <stdio.h>

int main(void) {
  int a[6] = {11, 22, 33, 44, 55, 999};

  int *p = a;

  printf("%d\n", *p);
  printf("%d\n", *(p + 1));

  // for (int i = 0; i < 6; i++) {
  //   printf("%d\n", *(p + i));
  // }

  while (*p != 999) {
    printf("%d\n", *p);
    p++;
  }

  return 0;
}
