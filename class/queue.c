#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
  int items[MAX_SIZE];
  int front;
  int rear;
};

void initQueue(struct Queue* q) {
  q->front = -1;
  q->rear = -1;
}

int isFull(struct Queue* q) {
  if ((q->front == 0 && q->rear == MAX_SIZE - 1) || (q->front == q->rear + 1)) {
    return 1;
  }
  return 0;
}

int isEmpty(struct Queue* q) {
  if (q->front == -1) {
    return 1;
  }
  return 0;
}

void enqueue(struct Queue* q, int value) {
  if (isFull(q)) {
    printf("Queue is full! Cannot enqueue.\n");
  } else {
    if (q->front == -1) {
      q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
  }
}

int dequeue(struct Queue* q) {
  int dequeuedValue;
  if (isEmpty(q)) {
    printf("Queue is empty! Cannot dequeue.\n");
    return -1;
  } else {
    dequeuedValue = q->items[q->front];
    if (q->front == q->rear) {
      initQueue(q);
    } else {
      q->front = (q->front + 1) % MAX_SIZE;
    }
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
  }
}

void display(struct Queue* q) {
  int i;
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue elements: ");
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
      printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[i]);
  }
}

int main() {
  struct Queue myQueue;
  initQueue(&myQueue);

  int choice;
  int value;

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
        enqueue(&myQueue, value);
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