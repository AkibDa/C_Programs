#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head = NULL;

void createDoublyLinkedList() {
  int size, data;
  printf("Enter the size of the doubly linked list you want: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter %d element: ", i + 1);
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
      head = newNode;
    } else {
      struct Node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->prev = temp;
    }
  }
}

void display() {
  if (head == NULL) {
    printf("No value present to display.\n");
    return;
  }
  struct Node* temp = head;
  printf("The elements in the doubly linked list are: ");
  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void insertAtAnyPosition(int value, int position){
  if(position < 1){
    printf("Invalid position to insert.\n");
    return;
  }
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  newNode->prev = NULL;
  if(position == 1){
    newNode->next = head;
    if(head != NULL){
      head->prev = newNode;
    }
    head = newNode;
    printf("%d is inserted at position %d.\n", value, position);
    return;
  }
  struct Node* temp = head;
  int count = 1;
  while(count < position - 1 && temp != NULL){
    temp = temp->next;
    count++;
  }
  if(temp == NULL){
    printf("Position is greater than the length of the linked list. Inserting at the end.\n");
    struct Node* tail = head;
    while(tail->next != NULL){
      tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    printf("%d is inserted at the end.\n", value);
    return;
  }
  newNode->next = temp->next;
  newNode->prev = temp;
  if(temp->next != NULL){
    temp->next->prev = newNode;
  }
  temp->next = newNode;
  printf("%d is inserted at position %d.\n", value, position);
}

void deleteAtAnyPosition(int position){
  if(head == NULL){
    printf("No value present to delete.\n");
    return;
  }
  if(position < 1){
    printf("Invalid position to delete.\n");
    return;
  }
  struct Node* temp = head;
  if(position == 1){
    head = head->next;
    if(head != NULL){
      head->prev = NULL;
    }
    free(temp);
    printf("Deleted element at position %d.\n", position);
    return;
  }
  int count = 1;
  while(count < position && temp != NULL){
    temp = temp->next;
    count++;
  }
  if(temp == NULL){
    printf("Position is greater than the length of the linked list. No deletion performed.\n");
    return;
  }
  temp->prev->next = temp->next;
  if(temp->next != NULL){
    temp->next->prev = temp->prev;
  }
  free(temp);
  printf("Deleted element at position %d.\n", position);
}

int main() {
  int choice, data, position;
  do {
    printf("Menu For Doubly Linked List functions:\n");
    printf("1: Create Doubly Linked List\n2: Insert at any position\n3: Delete at any position\n4: Display\n5: Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        createDoublyLinkedList();
        break;
      case 2:
        printf("Enter the position where you want to insert: ");
        scanf("%d", &position);
        printf("Enter the data you want to insert: ");
        scanf("%d", &data);
        insertAtAnyPosition(data, position);
        break;
      case 3:
        printf("Enter the position where you want to delete: ");
        scanf("%d", &position);
        deleteAtAnyPosition(position);
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 5);
  return 0;
}