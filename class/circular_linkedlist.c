#include<stdio.h>
#include<stdlib.h>


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