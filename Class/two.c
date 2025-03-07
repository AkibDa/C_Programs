//Write a C program to sum of all digits between 1 to 100 divisible by 5
#include <stdio.h>
int main ()
{
  int sum;
  for(int i=1;i<=100 ;i++)
  {
    if(i%5==0){
      sum=sum+i;
    }
  }
          printf("The sum of the number is %d", sum);
  
  return 0;
}