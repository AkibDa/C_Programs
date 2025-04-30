#include<stdio.h>

int* find_Multi(int* a, int* b, int* multi){
    *multi = *a * *b;
    return multi;
}
int main(){
    int a = 5;
    int b = 10;
    int multi;
    int* result = find_Multi(&a, &b, &multi);
    printf("%d", *result);
    return 0;
}