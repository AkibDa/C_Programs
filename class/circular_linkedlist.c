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
  printf("%d is inserted in the beginning.\n",data);
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
  int choice,data;
  do{
    printf("Menu For Linkedlist functions:\n");
    printf("0: Create Linkedlist\n1: Insert at beginning\n2: Insert at end\n3: Delete at start\n4: Delete at end\n5: Display\n6: Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 0:
        createLinkedList();
        break;
      case 1:
        printf("Enter the data u want to insert: ");
        scanf("%d",&data);
        insertAtStart(data);
        break;
      case 2:
        printf("Enter the data u want to insert: ");
        scanf("%d", &data);
        insertAtEnd(data);
        break;
      case 3:
        deleteAtStart();
        break;
      case 4:
        deleteAtEnd();
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid option !\n");
    }
  }while(choice != 6);
  return 0;
}