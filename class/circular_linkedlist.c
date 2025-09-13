#include<stdio.h>
#include<stdlib.h>

struct Node{int data; struct Node* next;};
struct Node* head = NULL;

void createLinkedList(){
  int size,data;
  printf("Enter the size of the circular linkedlist you want: ");
  scanf("%d",&size);
  for(int i=0;i<size;i++){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter %d element: ",i+1);
    scanf("%d",&data);
    newNode->data = data;
    if(head == NULL){
      head = newNode;
      newNode->next = head;
    }
    else{
      struct Node* temp = head;
      while(temp->next != head){
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
    }
  }
}

void insertAtStart(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(head == NULL){
    head = newNode;
    newNode->next = head;
  }
  else{
    struct Node* temp = head;
    while(temp->next != head){
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
  }
  printf("%d is inserted in the beginning.\n",data);
}

void insertAtEnd(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(head == NULL){
    head = newNode;
    newNode->next = head;
  }
  else{
    struct Node* temp = head;
    while(temp->next != head){
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }
  printf("%d is inserted in the end.\n",data);
}

void insertAtPosition(int data, int position){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(position == 1){
    insertAtStart(data);
    return;
  }
  struct Node* temp = head;
  int count = 1;
  while(count < position-1 && temp->next != head){
    temp = temp->next;
    count++;
  }
  if(count != position-1){
    printf("Position is greater than the length of the linkedlist. Inserting at the end.\n");
    insertAtEnd(data);
    return;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  printf("%d is inserted at position %d.\n",data,position);
}

void deleteAtStart(){
  if(head == NULL){
    printf("No value present to delete.\n");
    return;
  }
  if(head->next == head){
    free(head);
    head = NULL;
    printf("Deleted only element present.\n");
    return;
  }
  struct Node* temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  struct Node* toDelete = head;
  head = head->next;
  temp->next = head;
  free(toDelete);
  printf("First element deleted.\n");
}

void deleteAtEnd(){
  if(head == NULL){
    printf("No value present to delete.\n");
    return;
  }
  if(head->next == head){
    free(head);
    head = NULL;
    printf("Deleted only element present.\n");
    return;
  }
  struct Node* temp = head;
  struct Node* pretemp = head;
  while(temp->next != head){
    pretemp = temp;
    temp = temp->next;
  }
  pretemp->next = head;
  free(temp);
  printf("Deleted the last element.\n");
}

void deleteAtPosition(int position){
  if(head == NULL){
    printf("No value present to delete.\n");
    return;
  }
  if(position == 1){
    deleteAtStart();
    return;
  }
  struct Node* temp = head;
  struct Node* pretemp = head;
  int count = 1;
  while(count < position && temp->next != head){
    pretemp = temp;
    temp = temp->next;
    count++;
  }
  if(count != position){
    printf("Position is greater than the length of the linkedlist. Deleting at the end.\n");
    deleteAtEnd();
    return;
  }
  pretemp->next = temp->next;
  free(temp);
  printf("Deleted element at position %d.\n",position);
}

void display(){
  if(head == NULL){
    printf("No value present to display.\n");
    return;
  }
  struct Node* temp = head;
  printf("The elements in the circular linkedlist are: ");
  do{
    printf("%d -> ",temp->data);
    temp = temp->next;
  }while(temp != head);
  printf("%d (head)\n",head->data);
}

int main(){
  int choice,data, position;
  do{
    printf("Menu For Linkedlist functions:\n");
    printf("1: Create Linkedlist\n2: Insert at beginning\n3: Insert at end\n4: Insert at any position\n5: Delete at start\n6: Delete at end\n7: Delete at any position\n8: Display\n9: Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        createLinkedList();
        break;
      case 2:
        printf("Enter the data u want to insert: ");
        scanf("%d",&data);
        insertAtStart(data);
        break;
      case 3:
        printf("Enter the data u want to insert: ");
        scanf("%d", &data);
        insertAtEnd(data);
        break;
      case 4:
        printf("Enter the position where u want to insert: ");
        scanf("%d", &position);
        printf("Enter the data u want to insert: ");
        scanf("%d", &data);
        insertAtPosition(data, position);
        break;
      case 5:
        deleteAtStart();
        break;
      case 6:
        deleteAtEnd();
        break;
      case 7:
        printf("Enter the position where u want to delete: ");
        scanf("%d", &position);
        deleteAtPosition(position);
        break;
      case 8:
        display();
        break;
      case 9:
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid option !\n");
    }
  }while(choice != 9);
  return 0;
}