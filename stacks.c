#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int stack[MAXSIZE];
int top = -1;

/* Push an element onto the stack */
void push(void) {
  int value;

  if (top == MAXSIZE - 1) {
    printf("\nStack Overflow! Stack is full.\n");
    return;
  }

  printf("Enter value to push: ");
  scanf("%d", &value);

  top++;
  stack[top] = value;

  printf("%d pushed onto the stack.\n", value);
}

/* Check if stack is empty */
int isEmpty(void) {
  if (top == -1) {
    return 1;
  }
  return 0;
}

/* Remove an element from the stack */
void pop(void) {
  if (isEmpty()) {
    printf("\nStack Underflow! Stack is empty.\n");
    return;
  }

  printf("%d popped from the stack.\n", stack[top]);

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
