#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    fflush(stdout);
    scanf("%d",&n);
    if(n<1 || n>20){
        printf("\nInvalid input! Enter a number between 1 and 20.\n");
        
    }
    else {
        printf("\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                printf(" ");
            }
            for(int j=1;j<=i;j++){
                printf("%d",i);
                if(j<i){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}