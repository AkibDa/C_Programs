#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* root = NULL;

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* insert(struct Node* node, int data) {
  if (node == NULL) {
    return createNode(data);
  }
  if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  }
  return node;
}

void preorderTraversal(struct Node* node) {
  if (node != NULL) {
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
  }
}

void inorderTraversal(struct Node* node) {
  if (node != NULL) {
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
  }
}

void postorderTraversal(struct Node* node) {
  if (node != NULL) {
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
  }
}

int main() {
  int choice;
  int data[] = {50, 30, 20, 40, 70, 60, 80};
  do{
    printf("Menu For Binary Search Tree functions:\n");
    printf("1: Insert\n2: Preorder Traversal\n3: Inorder Traversal\n4: Postorder Traversal\n5: Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        for(int i = 0; i < 7; i++) {
          root = insert(root, data[i]);
          printf("%d is inserted in the BST.\n", data[i]);
        }
        break;
      case 2:
        printf("Preorder Traversal: ");
        preorderTraversal(root);
        printf("\n");
        break;
      case 3:
        printf("Inorder Traversal: ");
        inorderTraversal(root);
        printf("\n");
        break;
      case 4:
        printf("Postorder Traversal: ");
        postorderTraversal(root);
        printf("\n");
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }while (choice != 5);
  return 0;
}