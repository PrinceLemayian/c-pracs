#include <stdio.h>

typedef struct {
  char name[50];
  int age;
  float marks;
} Student;

int main() {
  Student s1 = {"Alice", 19, 60};
  Student *ptr = &s1;

  printf("Name: %s\n", ptr->name);
  printf("Age: %d\n", ptr->age);
  printf("Marks: %.2f\n", ptr->marks);

  return 0;
}
