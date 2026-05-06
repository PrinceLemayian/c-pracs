#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int age;
  float marks;
};

int main() {
  struct Student s1;

  strcpy(s1.name, "Alice");
  s1.age = 19;
  s1.marks = 60;

  printf("Name: %s\n", s1.name);
  printf("Age: %d\n", s1.age);
  printf("Marks: %.2f\n", s1.marks);

  return 0;
}
