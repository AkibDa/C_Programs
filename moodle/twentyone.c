#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    
    if(n<1 || n>20)
        printf("Invalid input! Enter a number between 1 and 20.\n");
    else {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=1;j++){
                printf("*");
            }
            for(int j=1;j<=(2*(n-i));j++){
                printf(" ");
            }
            for(int j=1;j<=1;j++){
                printf("* ");
            }
            printf("\n");
        }
    }
    
    return 0;
}