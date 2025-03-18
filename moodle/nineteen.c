#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: \n");
    scanf("%d",&n);
    if(n<1 || n>20)
        printf(" ");
    else {
        for(int i=1;i<=n;i++){
            int c=i;
            for(int j=1;j<=i;j++){
                printf("%d",c);
                c++;
                if(j<i)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}