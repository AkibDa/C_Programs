#include<stdio.h>
#include<stdlib.h>
int main(){
 int* ages;
 int* ptr;
 ptr = (int*)malloc(4*sizeof(int));

 if(ptr == NULL){
     printf("Memory allocation failed\n");
     return 1;
 }

 for(int i=0;i<4;i++){
   printf("Enter age: ");
   scanf("%d", ptr+i);
 }

 printf("The ages are:\n");
 for(int i=0;i<4;i++){
   printf("%d\n", *(ptr+i));
 }

 ptr = (int*)realloc(ptr, 6*sizeof(int));

 if(ptr == NULL){
     printf("Memory reallocation failed\n");
     return 1;
 }

 ages[4] = 32;
 ages[5] = 59;

 printf("The ages after reallocation are:\n");
 for(int i=0;i<6;i++){
   printf("%d\n", *(ptr+i));
 }

 free(ptr);

 return 0;
}