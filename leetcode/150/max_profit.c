#include <stdio.h>
#include <stdlib.h>

struct foo {
  int value;
  int index;
};

struct foo find_min(int *arr, int n) {
  int min_val = arr[0];
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (min_val > arr[i]) {
      min_val = arr[i];
      index = i;
    }
  }
  struct foo min = {min_val, index};
  return min;
}

int maxProfit(int *prices, int pricesSize) {

  if (pricesSize < 2) {
    return 0;
  }

  // lowest price of the stock
  struct foo min = find_min(prices, pricesSize);

  // if the lowest price of the stock is at the last day
  if (min.value == prices[pricesSize - 1]) {
    int temp[pricesSize];
    for (int i = 0; i < pricesSize - 1; i++) {
      temp[i] = prices[i];
    }
    min = find_min(temp, pricesSize - 1);
  }

  // highest value of stock after the lowest stock value day
  int max = prices[min.index + 1];
  for (int i = min.index + 1; i < pricesSize; i++) {
    if (prices[i] > max) {
      max = prices[i];
    }
  }

  int res = max - min.value < 0 ? 0 : max - min.value;
  return res;
}

int main(int argc, char **argv) {

  /* int prices[] = {7, 6, 4, 3, 1}; */
  int prices[] = {1};
  /* int prices[] = {7, 1, 5, 3, 6, 4}; */
  int size = sizeof(prices) / sizeof(int);
  maxProfit(prices, size);

  return 0;
}
