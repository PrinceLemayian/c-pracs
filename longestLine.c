#include <stdio.h>

#define MAXLINE 1000

int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  printf("Enter text (Ctrl+D/Ctrl+Z to stop):\n\n");

  while ((len = getline_custom(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("\nLongest line (%d characters):\n", max);
    printf("%s", longest);
  }

  return 0;
}

int getline_custom(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}
