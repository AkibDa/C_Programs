#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int main(){
  int *queue;
  int front = -1, rear = -1, choice, value;
  queue = (int *)malloc(MAX_SIZE * sizeof(int));
  if(queue == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  while (1) {
    printf("\n--- Queue Menu ---\n");
    printf("1. Enqueue (Add element)\n");
    printf("2. Dequeue (Remove element)\n");
    printf("3. Display queue\n");
    printf("4. Check if empty\n");
    printf("5. Check if full\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        enqueue(&queue, value);
        break;
      case 2:
        dequeue(&myQueue);
        break;
      case 3:
        display(&myQueue);
        break;
      case 4:
        if (isEmpty(&myQueue)) {
            printf("Queue is empty.\n");
        } else {
            printf("Queue is not empty.\n");
        }
        break;
      case 5:
        if (isFull(&myQueue)) {
            printf("Queue is full.\n");
        } else {
            printf("Queue is not full.\n");
        }
        break;
      case 6:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}