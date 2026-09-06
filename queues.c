#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Add an element
void enqueue(int value) {
  if (rear == SIZE - 1) {
    printf("Queue is full\n");
    return;
  }

  if (front == -1) {
    front = 0;
  }

  rear++;
  queue[rear] = value;
}

// Remove an element
void dequeue(void) {
  if (front == -1 || front > rear) {
    printf("Queue is empty\n");
    return;
  }

  printf("Removed: %d\n", queue[front]);
  front++;
}

// Display the queue
void display(void) {
  if (front == -1 || front > rear) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue: ");

  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }

  printf("\n");
}

int main(void) {
  enqueue(10);
  enqueue(20);
  enqueue(30);

  display();

  dequeue();
  display();

  enqueue(40);
  display();

  return 0;
}
