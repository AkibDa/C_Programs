#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void disp(){}

void search(){}

void sort(){}

void insert(){}

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
            insert(arr, size);
            printf("Element inserted successfully.\n");
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