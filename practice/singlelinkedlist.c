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
    printf("2. Delete the first element\n");
    printf("3. Display the list\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice){
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insertAtBeginning(data);
        break;
      case 2:
        deleteAtBeginning();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 4);
  return 0;
  
}