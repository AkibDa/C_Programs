#include<stdio.h>
int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    if(n<1) {
        printf("Number of rows must be at least 1.\n");
        return 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        for(int j=1;j<=2*(n-i);j++){
            printf("  ");
        }
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

// *               *
// * *           * *
// * * *       * * *
// * * * *   * * * *
// * * * * * * * * *