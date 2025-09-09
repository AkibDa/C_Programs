#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createLinkedList(){
    int size,data;
    printf("Enter the size of the linkedlist you want: ");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter %d element: ",i);
        scanf("%d",&data);
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtStart(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("%d is inserted in the beginning.\n",data);
}

void insertBefore(int data, int value){
    if(head == NULL){
        printf("No value present to insert before at.\n");
        return;
    }
    if(head->next == NULL){
        insertAtStart(data);
        return;
    }
    struct Node* temp = head;
    struct Node* pretemp = head;
    while(temp != NULL){
        if(temp->data == value){
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp;
            pretemp->next = newNode;
            printf("%d inserted before %d.\n",data,value);
            return;
        } else {
            pretemp = temp;
            temp = temp->next;
        }
    }
    printf("%d is not present in the linkedlist.\n",value);
}

void deleteStart(){
    if(head == NULL){
        printf("No value present to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = temp->next;
    free(temp);
    printf("First element deleted.\n");
}

void deleteEnd(){
    if(head == NULL){
        printf("No value present to delete.\n");
        return;
    }
    if(head->next == NULL){
        free(head);
        printf("Deleted only element present.\n");
    }
    struct Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Deleted the last element.\n");
}

void display(){
    if(head == NULL){
        printf("No element present to display.\n");
        return;
    }
    printf("The elements present in the linkedlist are:\n");
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice,value,data;
    do{
        printf("Menu For Linkedlist functions:\n");
        printf("0: Create Linkedlist\n1: Insert at beginning\n2: Insert before a value\n3: Delete at start\n4: Delete at end\n5: Display\n6: Exit\n");
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
                printf("Enter the value u want to insert before: ");
                scanf("%d",&value);
                printf("Enter the data u want to insert: ");
                scanf("%d", &data);
                insertBefore(data, value);
                break;
            case 3:
                deleteStart();
                break;
            case 4:
                deleteEnd();
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