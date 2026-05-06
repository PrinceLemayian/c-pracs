#include <stdio.h>
#include <string.h>

typedef struct {
  char name[50];
  int age;
  float marks;
} Student;

// Function to update student details using pointer
void updateStudent(Student *s) {
  printf("\n--- Update Student ---\n");

  printf("Enter new name: ");
  scanf("%s", s->name);

  printf("Enter new age: ");
  scanf("%d", &s->age);

  printf("Enter new marks: ");
  scanf("%f", &s->marks);
}

// Function to display student details
void displayStudent(Student *s) {
  printf("\n--- Student Details ---\n");
  printf("Name: %s\n", s->name);
  printf("Age: %d\n", s->age);
  printf("Marks: %.2f\n", s->marks);
}

int main() {
  Student s1 = {"John", 20, 75.5};
  Student *ptr = &s1;

  // Display original data
  displayStudent(ptr);

  // Update using pointer
  updateStudent(ptr);

  // Display updated data
  displayStudent(ptr);

  return 0;
}
