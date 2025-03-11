#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<=0)
        printf("Invalid input! Matrix order must be positive.");
    else {
        int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int m = arr[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] >= m){
                m = arr[i][j];
            }
        }
    }
    printf("Maximum element: %d",m);
    }
    
    return 0;
}