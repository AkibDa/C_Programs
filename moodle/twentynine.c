#include <stdio.h>
int main(){
    int n,s=0;
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input! Matrix order must be positive.");
    }
    else {
        int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                    s = s + arr[i][j];
                }
        }
    }
    printf("Trace of the matrix: %d",s);
    }
    return 0;
}