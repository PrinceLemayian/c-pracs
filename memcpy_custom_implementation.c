#include <stddef.h>
#include <stdio.h>
#include <string.h>

void *my_memcpy(void *dest, const void *src, size_t size) {
  char *d = (char *)dest;
  const char *s = (const char *)src;

  for (size_t i = 0; i < size; i++)
    d[i] = s[i];

  return dest;
}

int main(void) {
  char s[] = "Goats!";
  char t[100];

  int a[] = {11, 22, 33};
  int b[3];

  my_memcpy(b, a, 3 * sizeof(int)); // Copy 3 ints of data
  my_memcpy(t, s, 7);               // Copy 7 bytes including Null terminator

  printf("%s\n", t);
  printf("%d\n", b[1]);

  return 0;
}
