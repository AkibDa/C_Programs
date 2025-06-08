#include<stdio.h>

struct Student{
  int roll_no;
  char name[50];
  float marks;
}students[10];

int main(){
  float total_marks = 0.0;

  printf("Enter details of 10 students:\n");
  for(int i = 0; i < 10; i++){
    printf("Enter roll number: ");
    scanf("%d", &students[i].roll_no);
    printf("Enter name: ");
    scanf("%s", students[i].name);
    printf("Enter marks: ");
    scanf("%f", &students[i].marks);
  }

  printf("The details of the students are:\n");
  for(int i=0;i<10;i++){
    total_marks += students[i].marks;
    printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].roll_no, students[i].name, students[i].marks);
  }

  printf("Average marks: %.2f\n", total_marks / 10);

  return 0;
}