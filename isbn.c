#include <stdio.h>

int main(void) {
  int lang, pub, number, digit;

  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d", &lang, &pub, &number, &digit);

  printf("Language: %d\n", lang);
  printf("Publisher: %d\n", pub);
  printf("Book number: %d\n", number);
  printf("Check digit: %d\n", digit);
}
