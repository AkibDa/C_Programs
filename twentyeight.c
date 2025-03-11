#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==0)
        printf("Invalid input! Matrix order must be positive.");
    else {
        int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
    }
    
    return 0;
}