#include <stdio.h>

int count_length(const char *str) {
  int count = 0;

  while (str[count] != '\0') {
    count++;
  }

  return count;
}

int my_strlen(char *str) {
  char *p = str;

  while (*p != '\0') {
    p++;
  }

  return p - str;
}

int main(void) {
  char name[] = "Lemayian";

  printf("The length of your string is %d\n", my_strlen(name));

  return 0;
}
