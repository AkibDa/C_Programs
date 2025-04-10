#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n>0){
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("Reversed array: ");
        for(int i=n-1;i>=0;i--){
            printf("%d ",arr[i]);
        }
    }
    else{
        printf("Invalid input! Array size must be positive.");
    }
    return 0;
}