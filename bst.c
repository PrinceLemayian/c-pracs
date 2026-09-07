#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int data) {
  Node *newNode = malloc(sizeof(Node));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

Node *insert(Node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

void inorder(Node *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(Node *root) {
  if (root == NULL)
    return;

  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main(void) {
  Node *root = NULL;

  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 70);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Inorder: ");
  inorder(root);

  printf("\nPreorder: ");
  preorder(root);

  printf("\nPostorder: ");
  postorder(root);

  return 0;
}
