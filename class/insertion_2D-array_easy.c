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

    printf("Enter the row index (0-indexed) to insert into: ");
    scanf("%d", &rowIndex);

    printf("Enter the column index (0-indexed) to insert at (shifts elements right): ");
    scanf("%d", &colIndex);

    if (rowIndex < 0 || rowIndex >= rows || colIndex < 0 || colIndex > cols) { // colIndex can be 'cols' to append to row
        printf("Invalid position. Indices must be within bounds.\n");
    } else {
        // Shift elements in the specified row to the right
        // Note: If colIndex is 0 and cols is MAX_COLS, the last element might be 'lost'
        for (int j = cols - 1; j >= colIndex; j--) {
            arr[rowIndex][j + 1] = arr[rowIndex][j];
        }
        arr[rowIndex][colIndex] = elementToInsert; // Insert the element

        // If you were tracking the actual number of elements in each row,
        // you'd increment the column count for that specific row here.
        // For simplicity, we are assuming 'cols' is fixed.

        printf("2D Array after insertion (shifts elements in row):\n");
        print2DArray(arr, rows, cols);
    }

    return 0;
}