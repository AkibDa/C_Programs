#include <stdio.h>
#include <stdlib.h>

struct Item {
  int value;
  int weight;
};

int compare(const void *a, const void *b) {
  struct Item *item1 = (struct Item *)a;
  struct Item *item2 = (struct Item *)b;
  
  double r1 = (double)item1->value / item1->weight;
  double r2 = (double)item2->value / item2->weight;
  
  if (r1 < r2) return 1;
  else if (r1 > r2) return -1;
  else return 0;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
  qsort(arr, n, sizeof(struct Item), compare);

  int currentWeight = 0;   
  double finalValue = 0.0; 

  for (int i = 0; i < n; i++) {
    if (currentWeight + arr[i].weight <= W) {
      currentWeight += arr[i].weight;
      finalValue += arr[i].value;
    }
    else {
      int remainingWeight = W - currentWeight;
      finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
      break;
    }
  }

  return finalValue;
}

int main() {
  int W = 50;
  
  struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Maximum value in Fractional Knapsack = %.2f\n", fractionalKnapsack(W, arr, n));
  
  return 0;
}