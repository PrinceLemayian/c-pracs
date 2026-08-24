#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *description;
  int completed;
} Task;

void add_task(Task **tasks, int *count) {
  char buffer[100];

  printf("Enter task: ");
  fgets(buffer, sizeof(buffer), stdin);

  // Remove newline
  buffer[strcspn(buffer, "\n")] = '\0';

  // Increase array size
  Task *temp = realloc(*tasks, (*count + 1) * sizeof(Task));

  if (temp == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  *tasks = temp;

  // Allocate exactly enough memory for the description
  (*tasks)[*count].description = malloc((strlen(buffer) + 1) * sizeof(char));

  if ((*tasks)[*count].description == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  strcpy((*tasks)[*count].description, buffer);

  (*tasks)[*count].completed = 0;

  (*count)++;

  printf("Task added!\n");
}

void list_tasks(Task *tasks, int count) {
  if (count == 0) {
    printf("\nNo tasks.\n");
    return;
  }

  printf("\n--- Tasks ---\n");

  for (int i = 0; i < count; i++) {
    printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'x' : ' ',
           tasks[i].description);
  }
}

void complete_task(Task *tasks, int count) {
  int number;

  printf("Enter task number: ");
  scanf("%d", &number);
  getchar(); // consume newline

  if (number < 1 || number > count) {
    printf("Invalid task number.\n");
    return;
  }

  tasks[number - 1].completed = 1;

  printf("Task completed!\n");
}

void delete_task(Task **tasks, int *count) {
  int number;

  printf("Enter task number: ");
  scanf("%d", &number);
  getchar();

  if (number < 1 || number > *count) {
    printf("Invalid task number.\n");
    return;
  }

  int index = number - 1;

  // Free the description of the task being deleted
  free((*tasks)[index].description);

  // Move remaining tasks one position to the left
  for (int i = index; i < *count - 1; i++) {
    (*tasks)[i] = (*tasks)[i + 1];
  }

  (*count)--;

  // Shrink array
  if (*count == 0) {
    free(*tasks);
    *tasks = NULL;
  } else {
    Task *temp = realloc(*tasks, *count * sizeof(Task));

    if (temp != NULL) {
      *tasks = temp;
    }
  }

  printf("Task deleted!\n");
}

void free_tasks(Task *tasks, int count) {
  for (int i = 0; i < count; i++) {
    free(tasks[i].description);
  }

  free(tasks);
}

int main(void) {
  Task *tasks = NULL;
  int task_count = 0;
  int choice;

  while (1) {
    printf("\n===== TODO LIST =====\n");
    printf("1. Add task\n");
    printf("2. List tasks\n");
    printf("3. Complete task\n");
    printf("4. Delete task\n");
    printf("5. Exit\n");
    printf("=====================\n");

    printf("Choose: ");
    scanf("%d", &choice);
    getchar(); // consume newline

    switch (choice) {
    case 1:
      add_task(&tasks, &task_count);
      break;

    case 2:
      list_tasks(tasks, task_count);
      break;

    case 3:
      complete_task(tasks, task_count);
      break;

    case 4:
      delete_task(&tasks, &task_count);
      break;

    case 5:
      free_tasks(tasks, task_count);
      printf("Goodbye!\n");
      return 0;

    default:
      printf("Invalid choice.\n");
    }
  }
}
