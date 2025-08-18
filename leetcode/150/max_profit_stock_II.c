#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize) {

  int profits_each[pricesSize];
  int profit_each;
  int max_profit_each;

  for (int i = 0; i < pricesSize; i++) {
    max_profit_each = 0;
    for (int j = i + 1; j < pricesSize; j++) {
      profit_each = prices[j] - prices[i];
      if (profit_each > max_profit_each) {
        max_profit_each = profit_each;
      }
    }
    profits_each[i] = max_profit_each;
  }

  for (int i = 0; i < pricesSize; i++) {
    printf("%d \n", profits_each[i]);
  }
}

int main(int argc, char **argv) {

  int prices[] = {7, 1, 5, 3, 6, 4};
  int size = sizeof(prices) / sizeof(prices[0]);
  maxProfit(prices, size);

  return 0;
}
