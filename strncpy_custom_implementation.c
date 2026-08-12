#include <stdio.h>

char *copy_string(char *destination, const char *source, int max_capacity) {
  if (max_capacity <= 0)
    return destination;
  int available_capacity = max_capacity - 1;
  int i = 0;

  while (i < available_capacity && source[i] != '\0') {
    destination[i] = source[i];
    i++;
  }

  destination[i] = '\0';

  return destination;
}

int main(void) {
  char str1[30] = "Hello World, I am Lemayian \n";
  char str2[20];

  copy_string(str2, str1, 20);

  printf("Source is %s destination is %s", str1, str2);
}
