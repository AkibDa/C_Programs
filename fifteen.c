#include <stdio.h>
int main(){
    int n;
    char c;
    
    if(scanf("%d%c",&n,&c)!=2 || c!='\n'){
        printf("Invalid input");
    }
    else{
        if(n%2==0){
            printf("Even");
        }
        else {
            printf("Odd");
        }
    }
    
    return 0;
}