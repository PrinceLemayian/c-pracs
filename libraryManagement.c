#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
  int id;
  char title[50];
  char author[50];
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
  printf("\nEnter Book ID: ");
  scanf("%d", &library[bookCount].id);

  getchar(); // consume newline

  printf("Enter Book Title: ");
  fgets(library[bookCount].title, sizeof(library[bookCount].title), stdin);
  library[bookCount].title[strcspn(library[bookCount].title, "\n")] = '\0';

  printf("Enter Author Name: ");
  fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
  library[bookCount].author[strcspn(library[bookCount].author, "\n")] = '\0';

  bookCount++;

  printf("Book added successfully!\n");
}

void viewBooks() {
  if (bookCount == 0) {
    printf("\nNo books available.\n");
    return;
  }

  printf("\n--- Library Books ---\n");

  for (int i = 0; i < bookCount; i++) {
    printf("\nBook %d\n", i + 1);
    printf("ID: %d\n", library[i].id);
    printf("Title: %s\n", library[i].title);
    printf("Author: %s\n", library[i].author);
  }
}

void searchBook() {
  int id;
  printf("\nEnter Book ID to search: ");
  scanf("%d", &id);

  for (int i = 0; i < bookCount; i++) {
    if (library[i].id == id) {
      printf("\nBook Found!\n");
      printf("ID: %d\n", library[i].id);
      printf("Title: %s\n", library[i].title);
      printf("Author: %s\n", library[i].author);
      return;
    }
  }

  printf("Book not found.\n");
}

int main() {
  int choice;

  do {
    printf("\n===== Library Management System =====\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addBook();
      break;

    case 2:
      viewBooks();
      break;

    case 3:
      searchBook();
      break;

    case 4:
      printf("Goodbye!\n");
      break;

    default:
      printf("Invalid choice.\n");
    }

  } while (choice != 4);

  return 0;
}
