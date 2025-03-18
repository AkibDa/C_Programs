#include <stdio.h>
int main(){
    int n,temp = 0;
    scanf("%d",&n);
    if(n<1)
        printf("Invalid input! Number of elements must be positive.");
    else {
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n-1;i=i+2){
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1]=temp; 
        }
        for(int i=0;i<n;i++){
             printf("%d ",arr[i]);
        }
    }
    return 0;
}