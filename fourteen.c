#include <stdio.h>
int main(){
    int n,c=1;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input!");
    }
    else {
        for(int i=1;i<=n;i++){
            int j=1;
            for(int j=1;j<=i;j++){
              printf("%d",c);
              c++;
              if(j<i){
                  printf(" ");
              }
            }
            printf("\n");
        }
    }
    return 0;
}