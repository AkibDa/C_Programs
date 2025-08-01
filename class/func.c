#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void disp(){}

void search(){}

void sort(){}

void insert(int *arr, int size, int element, int position) {

    if(position < 0 || position > size) {
        printf("Invalid position!\n");
    }

    for(int i = size; i > position-1; i--) {
            arr[i] = arr[i - 1];
        }

    arr[position-1] = element;
    size++;

    printf("Element inserted successfully.\n");

    disp(arr, size);
}

void delete(){}

int main(){
    int *arr;
    int size, element, position;
    int ch;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    arr = (int *)malloc((MAXSIZE) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter your choice: ");
    printf("Press 1 to Insert\nPress 2 to Delete\nPress 3 to Search\nPress 4 to Sort\nPress 5 to Display\nPress 6 to Exit");
    scanf("%d", &ch);

    while(1){
        switch(ch) {
            case 1:
            if(size == MAXSIZE-1) {
                printf("Array is full. Cannot insert more elements.\n");
            } else {
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insert(arr, size, element, position);
            }
            break;
            case 2:
            delete(arr, size);
            break;
            case 3:
            search(arr, size);
            break;
            case 4:
            sort(arr, size);
            break;
            case 5:
            disp(arr, size);
            break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            break;
            default:
                printf("Invalid choice!");
        }
    }

    free(arr);

  return 0;
}