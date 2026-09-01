#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 // Maximum number of elements the stack can hold

int stack[MAXSIZE]; // Array that stores the stack elements
int top = -1;       // Index of the topmost element; -1 means the stack is empty

/* Push an element onto the stack */
void push(void) {
  int value;

  // The stack is full when top has reached the last valid index
  if (top == MAXSIZE - 1) {
    printf("\nStack Overflow! Stack is full.\n");
    return;
  }

  printf("Enter value to push: ");
  scanf("%d", &value);

  // Move top up to the next slot, then store the value there
  top++;
  stack[top] = value;

  printf("%d pushed onto the stack.\n", value);
}

/* Check if stack is empty */
int isEmpty(void) {
  // top starts at -1 and only goes up when we push.
  // So if top is still -1, no elements have been added and the stack is empty.
  if (top == -1) {
    return 1; // 1 means "yes, empty"
  }
  return 0; // 0 means "no, it has at least one element"
}

/* Remove an element from the stack */
void pop(void) {
  // Guard against removing from an empty stack (underflow)
  if (isEmpty()) {
    printf("\nStack Underflow! Stack is empty.\n");
    return;
  }

  // The current top element is the one being removed
  printf("%d popped from the stack.\n", stack[top]);

  // We don't erase the value; just lower top so that slot is
  // considered free and will be overwritten by the next push.
  top--;
}

/* Display stack */
void display(void) {
  int i;

  if (top == -1) {
    printf("\nStack is empty.\n");
    return;
  }

  printf("\nStack elements:\n");

  // Print from top down to the bottom so the most recent element shows first
  for (i = top; i >= 0; i--) {
    printf("%d\n", stack[i]);
  }
}

/* View top element */
void peek(void) {
  if (top == -1) {
    printf("\nStack is empty.\n");
    return;
  }

  // Show the top element without removing it
  printf("\nTop element: %d\n", stack[top]);
}

int main(void) {
  int choice;

  while (1) {

    printf("\n====================================\n");
    printf("             STACK\n");
    printf("====================================\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY\n");
    printf("4. PEEK\n");
    printf("5. EXIT\n");
    printf("====================================\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice) {

    case 1:
      push();
      break;

    case 2:
      pop();
      break;

    case 3:
      display();
      break;

    case 4:
      peek();
      break;

    case 5:
      printf("Exiting program...\n");
      return 0;

    default:
      printf("Invalid choice.\n");
    }
  }

  return 0;
}
