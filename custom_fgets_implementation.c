#include <stdio.h>

char *my_fgets(char *buffer, int maximum_capacity, FILE *stream) {
  if (maximum_capacity <= 0)
    return NULL;

  int available_capacity = maximum_capacity - 1;
  int i = 0;
  int c;

  while (i < available_capacity) {
    c = fgetc(stream);

    if (c == EOF) {
      if (i == 0)
        return NULL;
      break;
    }

    buffer[i++] = c;

    if (c == '\n')
      break;
  }

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

  fclose(fp);
  return 0;
}
