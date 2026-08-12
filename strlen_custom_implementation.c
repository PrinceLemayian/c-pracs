#include <stdio.h>

int count_length(const char *str) {
  int count = 0;

  while (str[count] != '\0') {
    count++;
  }

  return count;
}

int main(void) {
  char name[] = "Lemayian";

  printf("The length of your string is %d\n", count_length(name));

  return 0;
}
