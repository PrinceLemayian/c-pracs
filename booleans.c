#include <stdbool.h>
#include <stdio.h>

int main() {

  // (false == 0)
  // (true == 1)
  bool isOnline = true;
  bool isStudent = false;
  bool forSale = true;
  // prints 1
  // printf("%d", isOnline);

  if (isOnline) {
    printf("You are ONLINE\n");
  } else {
    printf("You are OFFLINE\n");
  }

  if (isStudent) {
    printf("You are a student\n");
  } else {
    printf("You are NOT a student\n");
  }

  if (forSale) {
    printf("That item is for sale\n");

  } else {
    printf("That item is NOT for sale\n");
  }
  return 0;
}
