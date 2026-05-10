#include <stdio.h>
#include <string.h>

typedef struct {
  char title[50];
  char author[50];
  int pages;
} Book;

// Function to edit book details using pointer
void editBook(Book *b) {
  printf("\n--- Edit Book Details ---\n");

  printf("Enter new title: ");
  scanf("%s", b->title);

  printf("Enter new author: ");
  scanf("%s", b->author);

  printf("Enter number of pages: ");
  scanf("%d", &b->pages);
}

// Function to display book details
void displayBook(Book *b) {
  printf("\n--- Book Information ---\n");
  printf("Title: %s\n", b->title);
  printf("Author: %s\n", b->author);
  printf("Pages: %d\n", b->pages);
}

int main() {
  Book b1 = {"AtomicHabits", "JamesClear", 320};

  // Pointer to structure
  Book *ptr = &b1;

  // Display original values
  displayBook(ptr);

  // Modify values using pointer
  editBook(ptr);

  // Display updated values
  displayBook(ptr);

  return 0;
}
