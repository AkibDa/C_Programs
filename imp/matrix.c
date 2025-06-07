#include<stdio.h>

int main(){
  int n;
  printf("Enter the size of the matrix (n x n): ");
  scanf("%d", &n);
  int a[n][n], b[n][n], c[n][n];
  printf("Enter elements of first matrix:\n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &a[i][j]);
    }
  }
  printf("Enter elements of second matrix:\n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &b[i][j]);
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      c[i][j] = 0; 
      for(int k = 0; k < n; k++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  printf("Resultant matrix after multiplication:\n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}