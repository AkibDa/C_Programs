#include <stdio.h>
int main(){
    int n,s = 0;
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input! Number of elements must be positive.");
    }
    else {
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                s = s + arr[i];
            }
        }
        printf("\nSum of even numbers: %d",s);
    }
    
    return 0;
}