#include <stdio.h>

struct car {
  char *name;
  float price;
  int speed;
};

void set_price(struct car *c, float new_price) { c->price = new_price; }

int main(void) {
  struct car saturn = {.speed = 175, .name = "Golf GTI"};

  set_price(&saturn, 1500000.00);

  printf("Price: %.2f\n", saturn.price);
}
