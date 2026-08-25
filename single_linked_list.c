#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node Node;

Node *start = NULL;

/* Create a new node */
Node *getNode(void) {
  Node *newNode = malloc(sizeof(Node));

  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter data: ");
  scanf("%d", &newNode->data);

  newNode->next = NULL;

  return newNode;
}

/* Count the number of nodes */
int countNode(Node *ptr) {
  int count = 0;

  while (ptr != NULL) {
    count++;
    ptr = ptr->next;
  }

  return count;
}

/* Create a list */
void createList(int n) {
  int i;
  Node *newNode;
  Node *temp;

  for (i = 0; i < n; i++) {
    newNode = getNode();

    if (start == NULL) {
      start = newNode;
    } else {
      temp = start;

      while (temp->next != NULL) {
        temp = temp->next;
      }

      temp->next = newNode;
    }
  }
}

/* Display list from left to right */
void traverse(void) {
  Node *temp = start;

  if (start == NULL) {
    printf("\nList is empty.\n");
    return;
  }

  printf("\nList: ");

  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }

  printf("NULL\n");
}

/* Display list from right to left using recursion */
void reverseTraverse(Node *ptr) {
  if (ptr == NULL) {
    return;
  }

  reverseTraverse(ptr->next);
  printf("%d -> ", ptr->data);
}

/* Insert at beginning */
void insertAtBeginning(void) {
  Node *newNode = getNode();

  newNode->next = start;
  start = newNode;

  printf("Node inserted at beginning.\n");
}

/* Insert at end */
void insertAtEnd(void) {
  Node *newNode = getNode();

  if (start == NULL) {
    start = newNode;
  } else {
    Node *temp = start;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = newNode;
  }

  printf("Node inserted at end.\n");
}

/* Insert at a specified middle position */
void insertAtMiddle(void) {
  int position;
  int nodeCount;
  int counter = 1;

  Node *newNode;
  Node *temp;
  Node *previous;

  nodeCount = countNode(start);

  printf("Enter position: ");
  scanf("%d", &position);

  if (position <= 1 || position >= nodeCount) {
    printf("Position must be between 2 and %d.\n", nodeCount);
    return;
  }

  newNode = getNode();

  temp = start;
  previous = NULL;

  while (counter < position) {
    previous = temp;
    temp = temp->next;
    counter++;
  }

  previous->next = newNode;
  newNode->next = temp;

  printf("Node inserted at position %d.\n", position);
}

/* Search for a value in the list */
void search(void) {
  int value;
  int position = 1;
  Node *temp = start;

  if (start == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Enter value to search: ");
  scanf("%d", &value);

  while (temp != NULL) {
    if (temp->data == value) {
      printf("Value %d found at position %d.\n", value, position);
      return;
    }
    temp = temp->next;
    position++;
  }

  printf("Value %d not found in the list.\n", value);
}

/* Delete a node by value */
void deleteByValue(void) {
  int value;
  Node *temp;
  Node *previous;

  if (start == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Enter value to delete: ");
  scanf("%d", &value);

  /* If the value is in the first node */
  if (start->data == value) {
    temp = start;
    start = start->next;
    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
    return;
  }

  /* Search for the value in the rest of the list */
  temp = start;
  previous = NULL;

  while (temp != NULL && temp->data != value) {
    previous = temp;
    temp = temp->next;
  }

  /* Value not found */
  if (temp == NULL) {
    printf("Value %d not found in the list.\n", value);
    return;
  }

  /* Unlink and free the node */
  previous->next = temp->next;
  printf("Deleted node with value: %d\n", temp->data);
  free(temp);
}

/* Display menu */
int menu(void) {
  int choice;

  printf("\n====================================\n");
  printf("       SINGLY LINKED LIST\n");
  printf("====================================\n");
  printf("1. Create a list\n");
  printf("2. Insert at beginning\n");
  printf("3. Insert at end\n");
  printf("4. Insert at middle\n");
  printf("5. Delete by value\n");
  printf("6. Search for a value\n");
  printf("7. Traverse left to right\n");
  printf("8. Traverse right to left\n");
  printf("9. Count nodes\n");
  printf("10. Exit\n");
  printf("====================================\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  return choice;
}

int main(void) {
  int choice;
  int numberOfNodes;

  while (1) {
    choice = menu();

    switch (choice) {

    case 1:
      if (start == NULL) {
        printf("Number of nodes to create: ");
        scanf("%d", &numberOfNodes);

        if (numberOfNodes <= 0) {
          printf("Number of nodes must be greater than 0.\n");
        } else {
          createList(numberOfNodes);
          printf("List created successfully.\n");
        }
      } else {
        printf("List already exists.\n");
      }
      break;

    case 2:
      insertAtBeginning();
      break;

    case 3:
      insertAtEnd();
      break;

    case 4:
      insertAtMiddle();
      break;

    case 5:
      deleteByValue();
      break;

    case 6:
      search();
      break;

    case 7:
      traverse();
      break;

    case 8:
      if (start == NULL) {
        printf("List is empty.\n");
      } else {
        printf("\nList in reverse: ");
        reverseTraverse(start);
        printf("NULL\n");
      }
      break;

    case 9:
      printf("Number of nodes: %d\n", countNode(start));
      break;

    case 10:
      printf("Exiting program...\n");
      return 0;

    default:
      printf("Invalid choice.\n");
    }
  }

  return 0;
}
