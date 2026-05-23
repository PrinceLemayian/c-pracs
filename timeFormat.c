#include <stdio.h>

int main(void) {
  int hours, minutes, seconds;

  printf("Enter time (hh:mm:ss): ");
  scanf("%d:%d:%d", &hours, &minutes, &seconds);

  printf("Formatted time: %02d:%02d:%02d\n", hours, minutes, seconds);

  return 0;
}
