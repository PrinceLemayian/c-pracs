#include <stdio.h>

int main(void) {
  FILE *fp = fopen("output.txt", "w");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open file\n");
    return 1;
  }

  fputc('H', fp);
  fputc('i', fp);
  fputc('!', fp);
  fputc('\n', fp);

  fputs("This is written with fputs.\n", fp);
  fputs("It writes a plain string, nothing more.\n", fp);

  int age = 19;
  float gpa = 3.85f;
  char name[] = "Lemayian";

  fprintf(fp, "Name: %s\n", name);
  fprintf(fp, "Age:  %d\n", age);
  fprintf(fp, "GPA:  %.2f\n", gpa);

  fclose(fp);

  printf("=== Contents of output.txt ===\n");
  fp = fopen("output.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not reopen file\n");
    return 1;
  }

  char line[128];
  while (fgets(line, sizeof line, fp) != NULL) {
    printf("%s", line);
  }

  fclose(fp);
  return 0;
}
