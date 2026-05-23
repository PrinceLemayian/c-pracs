#include <stdio.h>

int main(void) {
  int number, month, day, year;
  double price;

  printf("Enter item number: ");
  scanf("%d", &number);

  printf("Enter unit price: ");
  scanf("%lf", &price);

  printf("Enter purchase date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("Item\t\tUnit\t\tPurchase\n");
  printf("\t\tPrice\t\tDate\n");
  printf("%d\t\t$%6.2lf\t\t%02d/%02d/%02d\n", number, price, month, day, year);
}
