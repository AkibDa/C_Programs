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

struct Node* findMin(struct Node* node) {
  struct Node* current = node;

  while (current != NULL && current->left != NULL) {
    current = current->left;
  }

  return current;
}

struct Node* deleteNode(struct Node* root, int data) {
  if (root == NULL) {
    return root;
  }

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {    
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;    
    } else if (root->left == NULL) {
      struct Node* temp = root;
      root = root->right;      
      free(temp);              
    } else if (root->right == NULL) {
      struct Node* temp = root; 
      root = root->left;        
      free(temp);                   
    } else {
      struct Node* temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  
  return root;
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

struct Node* search(struct Node* root, int data)
{
  if (root == NULL || root->data == data)
    return root;

  if (data < root->data)
    return search(root->left, data);

  return search(root->right, data); 
}


int main() {
  int choice,key;
  int data[] = {50, 30, 20, 40, 70, 60, 80};
  do{
    printf("Menu For Binary Search Tree functions:\n");
    printf("1: Insert\n2: Preorder Traversal\n3: Inorder Traversal\n4: Postorder Traversal\n5: Delete Node\n6: Search\n7: Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        for(int i = 0; i < 7; i++) {
          root = insert(root, data[i]);
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
        printf("Enter the value to delete: ");
        scanf("%d", &key);
        if(deleteNode(root, key) != NULL) {
          root = deleteNode(root, key);
          printf("Value %d deleted from the BST.\n", key);
        } else {
          printf("Value %d not found in the BST.\n", key);
        }
        break;
      case 6: 
          printf("Enter the value to search: ");
          scanf("%d", &key);
          if (search(root, key) != NULL) {
            printf("Value %d found in the BST.\n", key);
          } else {
            printf("Value %d not found in the BST.\n", key);
          }
        break;
      case 7:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }while (choice != 7);
  return 0;
}