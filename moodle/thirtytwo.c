#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    if(num<=0){
        printf("Invalid input! Number of elements must be 25.");
    }
    else {
        int arr[num];
    int p=0, n=0, e=0, o=0;
    
    for(int i=0;i<25;i++){
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<25;i++){
        
        if(arr[i]>0){
            p++;
        }
        else if(arr[i]<0) {
            n++;
        }
        if(arr[i]%2==0){
            e++;
        }
        else {
            o++;
        }
        
    }
    
    printf("\nPositive numbers: %d",p);
    printf("\nNegative numbers: %d",n);
    printf("\nEven numbers: %d",e);
    printf("\nOdd numbers: %d",o);
    }
    
    
    return 0;
}