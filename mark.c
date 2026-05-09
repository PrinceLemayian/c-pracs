#include <stdio.h>

int main() {
  int marks[5];
  int sum = 0;
  float average;
  int highest, lowest;

  // Input marks
  printf("Enter marks for 5 students:\n");

  for (int i = 0; i < 5; i++) {
    printf("Student %d: ", i + 1);
    scanf("%d", &marks[i]);

    sum += marks[i];
  }

  // Initialize highest and lowest
  highest = marks[0];
  lowest = marks[0];

  // Find highest and lowest
  for (int i = 1; i < 5; i++) {
    if (marks[i] > highest) {
      highest = marks[i];
    }

    if (marks[i] < lowest) {
      lowest = marks[i];
    }
  }

  // Calculate average
  average = sum / 5.0;

  // Output results
  printf("\n--- Results ---\n");
  printf("Total Marks: %d\n", sum);
  printf("Average Marks: %.2f\n", average);
  printf("Highest Marks: %d\n", highest);
  printf("Lowest Marks: %d\n", lowest);

  // Grade classification
  if (average >= 70) {
    printf("Grade: A\n");
  } else if (average >= 60) {
    printf("Grade: B\n");
  } else if (average >= 50) {
    printf("Grade: C\n");
  } else {
    printf("Grade: Fail\n");
  }

  return 0;
}
