#include <stdio.h>

int main(void) {
  int a[] = {11, 22, 33, 44, 55};

  int *p = a;

  for (int i = 0; i < 5; i++)
    printf("%d\n", a[i]);

  for (int i = 0; i < 5; i++)
    printf("%d\n", p[i]);

  for (int i = 0; i < 5; i++)
    printf("%d\n", *(a + i));

  for (int i = 0; i < 5; i++)
    printf("%d\n", *(p + i));

  for (int i = 0; i < 5; i++)
    printf("%d\n", *(p++));
  // printf("%d\n", *(a++)); // Moving array variable produces an error

  return 0;
}
