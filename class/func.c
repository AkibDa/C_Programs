#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 15

void disp(int *arr, int size){

    if(size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements are: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;

}

void search(int *arr, int size, int element){

    for(int i=0;i<size;i++){
        if(arr[i] == element){
            printf("Element %d found at position %d\n", element, i + 1);
            return;
        }
    }
    printf("Element %d not found in the array.\n", element);
    return;

}

void sort(int *arr, int size){

    int temp=0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
    disp(arr, size);
    return;

}

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
    return;
}

void delete(int *arr, int size, int position){

    if (position < 1 || position > size) {
        printf("Invalid position!\n");
        return;
    }
    for(int i = position - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted successfully.\n");
    disp(arr, size);
    return;

}

int main(){
    int *arr;
    int size, element, position;
    int ch;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if(size<=0 || size > MAXSIZE) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAXSIZE);
        return 1;
    }

    arr = (int *)malloc((MAXSIZE) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter your choice:\n");
    printf("Press 1 to Insert\nPress 2 to Delete\nPress 3 to Search\nPress 4 to Sort\nPress 5 to Display\nPress 6 to Exit\n");
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
            if(size == 0) {
                printf("Array is empty. Cannot delete elements.\n");
            } else {
                printf("Enter the position to delete (1 to %d): ", size);
                scanf("%d", &position);
                delete(arr, size, position);
            }
            break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                search(arr, size, element);
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