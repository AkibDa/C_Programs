#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Global head pointer for the linked list, initialized to NULL
struct Node* head = NULL;

// Function to insert a new node at the beginning of the list
void insert_at_beginning(int data) {
  // Allocate memory for a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  new_node->data = data;
  new_node->next = head;
  head = new_node;
  printf("Element %d inserted at the beginning.\n", data);
}

// Function to insert a new node at a specific position
void insert_at_position(int data, int position) {
  if (position < 1) {
    printf("Position must be 1 or greater.\n");
    return;
  }

  if (position == 1) {
    insert_at_beginning(data);
    return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  new_node->data = data;

  struct Node* temp = head;
  for (int i = 1; i < position - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Invalid position. Position exceeds list size.\n");
    free(new_node); // Free the allocated memory for the new node
    return;
  }

  new_node->next = temp->next;
  temp->next = new_node;
  printf("Element %d inserted at position %d.\n", data, position);
}

// Function to delete a node with a specific value
void delete_element(int data) {
  if (head == NULL) {
    printf("List is empty. Cannot delete.\n");
    return;
  }

  // If the node to be deleted is the head
  if (head->data == data) {
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Element %d deleted.\n", data);
    return;
  }

  // Search for the node to be deleted
  struct Node* temp = head;
  struct Node* prev = NULL;
  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Element %d not found in the list.\n", data);
    return;
  }

  prev->next = temp->next;
  free(temp);
  printf("Element %d deleted.\n", data);
}

// Function to display the linked list
void display_list() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Linked list elements: ");
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
  int choice, data, position;

  while (1) {
    printf("\nSingly Linked List Operations\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at a specific position\n");
    printf("3. Delete an element\n");
    printf("4. Display list\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert_at_beginning(data);
        break;
      case 2:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        printf("Enter position to insert at: ");
        scanf("%d", &position);
        insert_at_position(data, position);
        break;
      case 3:
        printf("Enter element to delete: ");
        scanf("%d", &data);
        delete_element(data);
        break;
      case 4:
        display_list();
        break;
      case 5:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
