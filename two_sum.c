#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
  int key;
  struct Node *next;
} Node;

Node *table[TABLE_SIZE];

/* Hash function */
int hash(int key) { return abs(key) % TABLE_SIZE; }

/* Insert a key into the hashmap */
void insert(int key) {
  int index = hash(key);

  Node *newNode = malloc(sizeof(Node));

  newNode->key = key;
  newNode->next = table[index];

  table[index] = newNode;
}

/* Check whether a key exists */
int contains(int key) {
  int index = hash(key);

  Node *current = table[index];

  while (current != NULL) {
    if (current->key == key)
      return 1;

    current = current->next;
  }

  return 0;
}

/* Free hashmap memory */
void freeTable(void) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Node *current = table[i];

    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      free(temp);
    }

    table[i] = NULL;
  }
}

/* Two Sum */
int twoSum(int arr[], int size, int target) {
  for (int i = 0; i < size; i++) {
    int complement = target - arr[i];

    if (contains(complement)) {
      printf("Pair found: %d + %d = %d\n", complement, arr[i], target);

      return 1;
    }

    insert(arr[i]);
  }

  return 0;
}

int main(void) {
  int arr[] = {2, 7, 11, 15};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 9;

  if (!twoSum(arr, size, target))
    printf("No pair found\n");

  freeTable();

  return 0;
}
