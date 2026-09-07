#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int middle = left + (right - left) / 2;

    if (arr[middle] == target) {
      return middle;
    } else if (target < arr[middle]) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  return -1;
}

int main(void) {
  int numbers[] = {10, 20, 30, 40, 50, 60, 70};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  int target = 50;

  int result = binarySearch(numbers, size, target);

  if (result != -1) {
    printf("Found at index %d\n", result);
  } else {
    printf("Not found\n");
  }

  return 0;
}
