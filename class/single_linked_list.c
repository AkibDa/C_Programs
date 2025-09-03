#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  newNode->data = data;

  newNode->next = head;

  head = newNode;
  printf("Inserted %d at the beginning.\n", data);
}

void insertAtEnd(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    printf("Inserted %d at the end (list was empty).\n", data);
    return;
  }

  struct Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
  printf("Inserted %d at the end.\n", data);
}

void insertNode(int key, int newData) {
  struct Node* temp = head;
  while (temp != NULL && temp->data != key) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Node with key %d not found. Cannot insert.\n", key);
    return;
  }

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  newNode->data = newData;

  newNode->next = temp->next;
  temp->next = newNode;
  printf("Inserted %d after node with key %d.\n", newData, key);
}

void deleteAtBeginning() {
  if (head == NULL) {
    printf("List is empty. Cannot delete from the beginning.\n");
    return;
  }

  struct Node* temp = head;

  head = head->next;

  free(temp);
  printf("Deleted the first element from the list.\n");
}

void deleteAtEnd() {
  if (head == NULL) {
    printf("List is empty. Cannot delete from the end.\n");
    return;
  }

  if (head->next == NULL) {
    free(head);
    head = NULL;
    printf("Deleted the only element from the list.\n");
    return;
  }

  struct Node* temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  free(temp->next);

  temp->next = NULL;
  printf("Deleted the last element from the list.\n");
}

void deleteNode(int key) {
  struct Node *temp = head, *prev = NULL;

  if (temp != NULL && temp->data == key) {
    head = temp->next; 
    free(temp);        
    printf("Node with key %d deleted.\n", key);
    return;
  }

  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Node with key %d not found in the list.\n", key);
    return;
  }

  prev->next = temp->next;

  free(temp);
  printf("Node with key %d deleted.\n", key);
}

void displayList() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  struct Node* temp = head;
  printf("Linked List: ");
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
    int choice, data, key, newData;

    do {
      printf("\n--- Linked List Menu ---\n");
      printf("1. Insert at the beginning\n");
      printf("2. Insert at the end\n");
      printf("3. Insert after a specific key\n");
      printf("4. Delete a node with a value\n");
      printf("5. Delete the first element\n");
      printf("6. Delete the last element\n");
      printf("7. Display the list\n");
      printf("8. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          printf("Enter data to insert: ");
          scanf("%d", &data);
          insertAtBeginning(data);
          break;
        case 2:
          printf("Enter data to insert: ");
          scanf("%d", &data);
          insertAtEnd(data);
          break;
        case 3:
          printf("Enter the key to insert after: ");
          scanf("%d", &key);
          printf("Enter the new data to insert: ");
          scanf("%d", &newData);
          insertNode(key, newData);
          break;
        case 4:
          printf("Enter key to delete: ");
          scanf("%d", &key);
          deleteNode(key);
          break;
        case 5:
          deleteAtBeginning();
          break;
        case 6:
          deleteAtEnd();
          break;
        case 7:
          displayList();
          break;
        case 8:
          printf("Exiting program.\n");
          break;
        default:
          printf("Invalid choice. Please try again.\n");
      }
    } while (choice != 8);

    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
      nextNode = current->next;
      free(current);
      current = nextNode;
    }

    return 0;
}
