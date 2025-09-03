#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL){
    printf("Memory allocation failed!\n");
    return;
  }
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  printf("Inserted %d at the beginning.\n", data);
}

void insertAtEnd(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL){
    printf("Memory allocation failed!\n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;
  if(head == NULL){
    head = newNode;
    printf("Inserted %d at the end (list was empty).\n", data);
    return;
  }
  struct Node* temp = head;
  while (temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  printf("Inserted %d at the end.\n", data);
}

void deleteAtBeginning(){
  if (head == NULL){
    printf("List is empty. Cannot delete from the beginning.\n");
    return;
  }
  struct Node* temp = head;
  head = head->next;
  free(temp);
  printf("Deleted the first element from the list.\n");
}

void deletedAtEnd(){
  if (head == NULL){
    printf("List is empty. Cannot delete from the end.\n");
    return;
  }
  if(head->next == NULL){
    free(head);
    head = NULL;
    printf("Deleted the only element from the list.\n");
    return;
  }
  struct Node* temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  printf("Deleted the last element from the list.\n");
}

void display(){
  if (head == NULL){
    printf("The list is empty.\n");
    return;
  }
  struct Node* temp = head;
  printf("Linked List: ");
  while (temp != NULL){
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main(){
  int choice, data;
  do
  {
    printf("\n--- Linked List Menu ---\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Delete the first element\n");
    printf("4. Delete the last element\n");
    printf("5. Display the list\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice){
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
        deleteAtBeginning();
        break;
      case 4:
        deletedAtEnd();
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 6);
  return 0;
  
}