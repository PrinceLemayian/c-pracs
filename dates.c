#include <stdio.h>

int main(void) {
  int month, day, year;

  printf("Enter a date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("You entered the date %02d%02d%02d\n", year, month, day);

  return 0;
}
