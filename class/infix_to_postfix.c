#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 10

// Stack implementation
char stack[MAX_SIZE];
int top = -1;

void push(char item) {
  if (top >= MAX_SIZE - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stack[++top] = item;
}

char pop() {
  if (top < 0) {
    printf("Stack Underflow\n");
    return '\0';
  }
  return stack[top--];
}

int precedence(char operator) {
  switch (operator) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return -1;
  }
}

int isOperator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char* infix, char* postfix) {
  int i, j = 0;
  char ch, popped;

  for (i = 0; infix[i] != '\0'; i++) {
    ch = infix[i];

    if (ch == ' ') {
      continue; // skip whitespace
    }
    else if (isalnum(ch)) {
      postfix[j++] = ch;
    }
    else if (ch == '(') {
      push(ch);
    }
    else if (ch == ')') {
      while ((popped = pop()) != '(') {
        postfix[j++] = popped;
      }
    }
    else if (isOperator(ch)) {
      while (top != -1 && precedence(ch) <= precedence(stack[top])) {
        postfix[j++] = pop();
      }
      push(ch);
    }
  }

  while (top != -1) {
      postfix[j++] = pop();
  }

  postfix[j] = '\0'; 
}

int main() {

  char *infix = (char*)malloc(MAX_SIZE * sizeof(char));
  char *postfix = (char*)malloc(MAX_SIZE * sizeof(char));
  
  if (infix == NULL || postfix == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("Infix to Postfix Converter\n");

  printf("Enter an infix expression: ");
  fgets(infix, MAX_SIZE, stdin);
  infix[strcspn(infix, "\n")] = '\0'; 

  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}