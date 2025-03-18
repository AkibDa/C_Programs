#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, *p, s, c=0;
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input! Array size must be positive.");
    }
    else{
       p = (int *)malloc(n*sizeof(int));
       if(p==NULL)
        printf("Memory allocation failed.");
    srand(time(NULL));
    for(int i=0;i<n;i++){
        *(p+i)=rand()%9900+100;
    }
    printf(" Generated array: <random_numbers>");
    // for(int i=0;i<n;i++){
    //     printf("%d ",*(p+i));
    // }
    scanf("%d",&s);
    if(s>=100 && s<=10000){
        for(int i=0;i<n;i++){
        if(s == *(p+i)){
            c++;
        }
        else {
            c=0;
        }
    }
    if(c==1){
        printf("\n%d is found in the array.",s);
    }
    else {
        printf("\n%d is not found in the array.",s);
    }
    }
    else {
        printf("Invalid input! Number must be between 100 and 10000.");
    }
    
    free(p); 
    }
    
    return 0;
}