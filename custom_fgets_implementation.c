#include <stdio.h>

char *my_fgets(char *buffer, int maximum_capacity, FILE *stream) {
  if (maximum_capacity <= 0) {
    return NULL;
  }

  int available_capacity = maximum_capacity - 1;
  int i = 0;
  int c = fgetc(stream);

  if (c == EOF) {
    return NULL;
  }

  while (i < available_capacity) {
    if (c == EOF) {
      buffer[i] = '\0';
      return buffer;
    }
    buffer[i] = c;
    if (c == '\n') {
      buffer[i] = '\n';
      buffer[i + 1] = '\0';
      return buffer;
    }
    c = fgetc(stream);
    i++;
  };

  buffer[i] = '\0';
  return buffer;
}

int main(void) {
  FILE *fp;
  char s[1024];
  int lineCounter = 0;

  fp = fopen("quote.txt", "r");

  if (fp == NULL) {
    printf("The file failed to open.");
    return 1;
  }

  while ((my_fgets(s, sizeof s, fp)) != NULL) {
    printf("%d: %s", ++lineCounter, s);
  };
}
