#include <stdio.h>
int main(){
    int y;
    scanf("%d",&y);
    
    (y%400 == 0) || (y%4==0 && y%100 !=0)?printf("%d is a leap year.",y):printf("%d is not a leap year.",y);
    
    return 0;
}