#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char op) {
  stack[++top] = op;
}

char pop() {
  if (top == -1) {
    return '\0';
  }
  return stack[top--];
}

int isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 2;
  } else if (ch == '^') {
    return 3;
  }
  return 0;
}

void infixToPostfix(char* infix) {
  int i, j;
  char postfix[MAX_SIZE];
  i = j = 0;

  while (infix[i] != '\0') {
    if (isalnum(infix[i])) {
      postfix[j++] = infix[i];
    } else if (infix[i] == '(') {
      push(infix[i]);
    } else if (infix[i] == ')') {
        while (top != -1 && stack[top] != '(') {
          postfix[j++] = pop();
        }
        if (top != -1 && stack[top] == '(') {
          pop(); // Pop '('
        }
    } else if (isOperator(infix[i])) {
        while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
          postfix[j++] = pop();
        }
        push(infix[i]);
    }
    i++;
  }

  while (top != -1) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';

  printf("Postfix expression: %s\n", postfix);
}

int main() {
  char *expression;
  expression = (char *)malloc(MAX_SIZE * sizeof(char));
  if (expression == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }
  printf("Infix to Postfix Converter\n");
  printf("Enter an infix expression: ");
  fgets(expression, MAX_SIZE, stdin);
  expression[strcspn(expression, "\n")] = '\0';

  infixToPostfix(expression);

  return 0;
}