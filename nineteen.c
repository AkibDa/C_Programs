#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    if(n<1 || n>20)
        printf("Invalid input! Enter a number between 1 and 20.");
    else {
        for(int i=0;i<n;i++){
            for(int j=1;j<=i;j++){
                printf(" * ");
                if(j<i)
                    printf(" ");
                
            }
            printf("\n");
        }
    }
    
    return 0;
}