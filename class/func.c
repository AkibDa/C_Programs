#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE

int main(){
    int *arr;
    int size, element, position;
    int ch;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    arr = (int *)malloc((size + 1) * sizeof(int));
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
        swtich(ch) {
            case 6:
                printf("Exiting...\n");
                exit(0);
        }
    }


    free(arr);


  return 0;
}