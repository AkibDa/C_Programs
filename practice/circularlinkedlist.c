#include<stdio.h>
#include<stdlib.h>

struct Node { int data; struct Node* next;};

struct Node* head = NULL;

void createLinkedList(){
  int size,data;
  printf("Enter the number of nodes: ");
  scanf("%d",&size);
  for(int i=0;i<size;i++){
    printf("Enter data for node %d: ",i+1);
    scanf("%d",&data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    newNode->data = data;
    if(head == NULL){
      head = newNode;
      newNode->next = head;
    } else {
      while(ptr->next != head){
        ptr = ptr->next;
      }
      ptr->next = newNode;
      newNode->next = head;
    }
  }
  printf("Circular Linked List created successfully.\n");
}

void insertAtBeginning(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  struct Node* ptr = head;
  newNode->data = data;
  if(head == NULL){
    head = newNode;
    newNode->next = head;
  } else {
    while(ptr->next != head){
      ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
  }
}

void insertAtEnd(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  struct Node* ptr = head;
  newNode->data = data;
  if(head == NULL){
    head = newNode;
    newNode->next = head;
  } else {
    while(ptr->next != head){
      ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
  }
}

void insertAtPosition(int position, int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  struct Node* ptr = head;
  newNode->data = data;
  if(position == 0){
    insertAtBeginning(data);
    return;
  }
  int count = 0;
  while(count < position - 1 && ptr->next != head){
    ptr = ptr->next;
    count++;
  }
  if(count != position - 1){
    printf("Position out of bounds. Inserting at end.\n");
    insertAtEnd(data);
    return;
  }
  newNode->next = ptr->next;
  ptr->next = newNode;
}

void deleteFromBeginning(){
  if(head == NULL){
    printf("List is empty. Cannot delete.\n");
    return;
  }
  if(head->next == head){
    free(head);
    head = NULL;
    return;
  }
  struct Node* ptr = head;
  while(ptr->next != head){
    ptr = ptr->next;
  }
  ptr->next = head->next;
  free(head);
  head = ptr->next;
  printf("Deleted node from beginning.\n");
}

void deleteFromEnd(){
  if(head == NULL){
    printf("List is empty. Cannot delete.\n");
    return;
  }
  if(head->next == head){
    free(head);
    head = NULL;
    return;
  }
  struct Node* ptr = head;
  struct Node* preptr = head;
  while(ptr->next != head){
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = head;
  free(ptr);
  printf("Deleted node from end.\n");
}

void deleteFromPosition(int position){
  if(head == NULL){
    printf("List is empty. Cannot delete.\n");
    return;
  }
  if(position == 0){
    deleteFromBeginning();
    return;
  }
  struct Node* ptr = head;
  struct Node* preptr = head;
  int count = 0;
  while(count < position && ptr->next != head){
    preptr = ptr;
    ptr = ptr->next;
    count++;
  }
  if(count != position){
    printf("Position out of bounds. Cannot delete.\n");
    return;
  }
  preptr->next = ptr->next;
  free(ptr);
  printf("Deleted node from position %d.\n", position);
}

void displayList(){
  if(head == NULL){
    printf("List is empty.\n");
    return;
  }
  struct Node* ptr = head;
  printf("Circular Linked List: ");
  do{
    printf("%d -> ",ptr->data);
    ptr = ptr->next;
  }while(ptr->next != head);
  printf("(head: %d)\n", head->data);
}

int main(){
  int choice,data,position;
  do{
    printf("Menu for Circular Linked List Operations:\n");
    printf("0. CreateLinkedList\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Display List\n8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 0: createLinkedList(); break;
      case 1: printf("Enter data to insert at beginning: "); scanf("%d",&data); insertAtBeginning(data); break;
      case 2: printf("Enter data to insert at end: "); scanf("%d",&data); insertAtEnd(data); break;
      case 3: printf("Enter position and data to insert: "); scanf("%d %d",&position,&data); insertAtPosition(position,data); break;
      case 4: deleteFromBeginning(); break;
      case 5: deleteFromEnd(); break;
      case 6: printf("Enter position to delete from: "); scanf("%d",&position); deleteFromPosition(position); break;
      case 7: displayList(); break;
      case 8: printf("Exiting...\n"); break;
      default: printf("Invalid choice. Please try again.\n");
    }
  }while(choice!=8);
  return 0;
}