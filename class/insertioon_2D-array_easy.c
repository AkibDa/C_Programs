#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 5

// Function to print a 2D array
void print2DArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int elementToInsert, rowIndex, colIndex;

    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS || rows < 1 || cols < 1) {
        printf("Invalid dimensions. Max dimensions are %dx%d.\n", MAX_ROWS, MAX_COLS);
        return 1;
    }

    printf("Enter %d elements for the 2D array:\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the element to insert: ");
    scanf("%d", &elementToInsert);

    printf("Enter the row index (0-indexed) to insert at: ");
    scanf("%d", &rowIndex);

    printf("Enter the column index (0-indexed) to insert at: ");
    scanf("%d", &colIndex);

    if (rowIndex < 0 || rowIndex >= rows || colIndex < 0 || colIndex >= cols) {
        printf("Invalid position. Indices must be within the current array bounds.\n");
    } else {
        arr[rowIndex][colIndex] = elementToInsert; // Overwrite the existing element

        printf("2D Array after insertion (overwrite):\n");
        print2DArray(arr, rows, cols);
    }

    return 0;
}