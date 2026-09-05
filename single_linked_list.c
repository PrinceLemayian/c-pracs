#include <stdio.h>
#include <stdlib.h>

// Defines blueprint for the node
struct Node {
  int data;
  struct Node *next; // Points to the next node of the same type
};

typedef struct Node Node;

// Global pointer marking the beginning of the list
Node *start = NULL; // NULL means the list is empty

/* Read an integer safely.
   Returns 1 on success, 0 if the input was not a valid integer.
   On failure it flushes the rest of the line so the bad characters
   don't get read again (which would otherwise cause infinite loops). */
int readInt(int *out) {
  if (scanf("%d", out) != 1) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
      // discard leftover characters from the bad input
    }
    return 0;
  }
  return 1;
}

/* Create a new node */
Node *getNode(void) {
  Node *newNode = malloc(sizeof(Node));

  // Malloc returns NULL when it fails
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter data: ");
  while (!readInt(&newNode->data)) {
    printf("Invalid input. Enter an integer: ");
  }

  // The node doesn't point anywhere yet
  newNode->next = NULL;

  return newNode;
}

/* Count the number of nodes */
int countNode(Node *ptr) {
  int count = 0;

  // Walk the list one node at a time and increment counter
  while (ptr != NULL) {
    count++;
    ptr = ptr->next;
  }

  return count;
}

/* Free every node in the list */
void freeList(void) {
  Node *temp = start;
  Node *nextNode;

  // Walk the list, saving the next pointer BEFORE freeing the current node.
  // If we freed first, temp->next would be reading freed memory.
  while (temp != NULL) {
    nextNode = temp->next;
    free(temp);
    temp = nextNode;
  }

  // Reset the head so the list is a valid empty list again
  start = NULL;
}

/* Create a list */
void createList(int n) {
  int i;
  Node *newNode; // Holds freshly created node each iteration
  Node *temp;    // Used to walk to the end of the list so we can attach the new
                 // node there

  for (i = 0; i < n; i++) {
    /*
    For each iteration, a brand new node is created with the user's input,
    each node starts completely disconnected from the list so getNode() sets it
    next to NULL
    */
    newNode = getNode();

    // Condition for when list is empty (1st iteration)
    // The first node becomes the head since list is empty
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
  Node *temp = start; // Start walking from the head

  if (start == NULL) {
    printf("\nList is empty.\n");
    return;
  }

  printf("\nList: ");

  // Visit each node and print its data until we reach the end (NULL)
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }

  printf("NULL\n");
}

/* Display list from right to left using recursion */
void reverseTraverse(Node *ptr) {
  // Base case: stop when we run past the end of the list
  if (ptr == NULL) {
    return;
  }

  // First dive all the way to the last node, then print on the way back.
  // This prints later nodes before earlier ones, giving reverse order.
  reverseTraverse(ptr->next);
  printf("%d -> ", ptr->data);
}

/* Insert at beginning */
void insertAtBeginning(void) {
  Node *newNode = getNode();

  // Point the new node at the current head, then make it the new head
  newNode->next = start;
  start = newNode;

  printf("Node inserted at beginning.\n");
}

/* Insert at end */
void insertAtEnd(void) {
  Node *newNode = getNode();

  // If the list is empty, the new node simply becomes the head
  if (start == NULL) {
    start = newNode;
  } else {
    Node *temp = start;

    // Walk to the last node (the one whose next is NULL)
    while (temp->next != NULL) {
      temp = temp->next;
    }

    // Attach the new node after the current last node
    temp->next = newNode;
  }

  printf("Node inserted at end.\n");
}

/* Insert at a specified middle position */
void insertAtMiddle(void) {
  int position;
  int nodeCount;
  int counter = 1; // Tracks which node we are currently standing on

  Node *newNode;
  Node *temp;     // Will point to the node currently at the target position
  Node *previous; // Will point to the node just before temp

  nodeCount = countNode(start);

  printf("Enter position: ");
  if (!readInt(&position)) {
    printf("Invalid input. Position must be an integer.\n");
    return;
  }

  // Only allow real middle positions (not the head, not the end/beyond)
  if (position <= 1 || position >= nodeCount) {
    printf("Position must be between 2 and %d.\n", nodeCount);
    return;
  }

  newNode = getNode();

  temp = start;
  previous = NULL;

  // Step forward until temp sits at the target position,
  // keeping previous one node behind it
  while (counter < position) {
    previous = temp;
    temp = temp->next;
    counter++;
  }

  // Splice the new node in between previous and temp
  previous->next = newNode;
  newNode->next = temp;

  printf("Node inserted at position %d.\n", position);
}

/* Search for a value in the list */
void search(void) {
  int value;
  int position = 1;   // Position numbering starts at 1 for the first node
  Node *temp = start; // Begin the search from the head of the list

  // Nothing to search if the list has no nodes
  if (start == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Enter value to search: ");
  if (!readInt(&value)) {
    printf("Invalid input. Value must be an integer.\n");
    return;
  }

  // Walk through the list one node at a time
  while (temp != NULL) {
    // If the current node holds the value we want, report where it is and stop
    if (temp->data == value) {
      printf("Value %d found at position %d.\n", value, position);
      return;
    }
    // Otherwise move to the next node and count it as the next position
    temp = temp->next;
    position++;
  }

  // We reached the end (NULL) without finding the value
  printf("Value %d not found in the list.\n", value);
}

/* Delete a node by value */
void deleteByValue(void) {
  int value;
  Node *temp;     // Will point to the node we want to delete
  Node *previous; // Will point to the node just before temp

  // Can't delete anything from an empty list
  if (start == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Enter value to delete: ");
  if (!readInt(&value)) {
    printf("Invalid input. Value must be an integer.\n");
    return;
  }

  /* If the value is in the first node */
  // The head is a special case because there is no node before it.
  // We move the head forward, then free the old first node.
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

  // Move forward until temp lands on the matching value,
  // while previous trails one node behind temp.
  // The loop also stops if we hit the end (temp == NULL).
  while (temp != NULL && temp->data != value) {
    previous = temp;
    temp = temp->next;
  }

  /* Value not found */
  // If temp is NULL, we walked off the end without a match
  if (temp == NULL) {
    printf("Value %d not found in the list.\n", value);
    return;
  }

  /* Unlink and free the node */
  // Bypass temp by connecting previous straight to temp's next node,
  // then free temp's memory so it is fully removed.
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
  printf("10. Delete entire list\n");
  printf("11. Exit\n");
  printf("====================================\n");
  printf("Enter your choice: ");

  // If the user types something that isn't a number, readInt flushes the
  // bad input and we return -1 so main's default case reports it.
  if (!readInt(&choice)) {
    return -1;
  }

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

        if (!readInt(&numberOfNodes)) {
          printf("Invalid input. Please enter an integer.\n");
        } else if (numberOfNodes <= 0) {
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
      if (start == NULL) {
        printf("List is already empty.\n");
      } else {
        freeList();
        printf("Entire list deleted.\n");
      }
      break;

    case 11:
      printf("Exiting program...\n");
      freeList();
      return 0;

    default:
      printf("Invalid choice.\n");
    }
  }

  return 0;
}
