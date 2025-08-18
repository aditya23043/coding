/* 121: two pointer problem */

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize);

int main(int argc, char **argv) {

  int prices[] = {7, 1, 5, 3, 6, 4};
  int size = sizeof(prices) / sizeof(prices[0]);
  printf("%d\n", maxProfit(prices, size));

  return 0;
}

int maxProfit(int *prices, int pricesSize) {
  int p1, p2;
  int max_profit = 0;

  if (pricesSize == 1) {
    return 0;
  }

  p1 = 0;
  p2 = 1;

  while (p2 < pricesSize) {
    if (prices[p1] < prices[p2]) {
      if ((prices[p2] - prices[p1]) > max_profit)
        max_profit = prices[p2] - prices[p1];
    } else {
      p1 = p2;
    }
    p2++;
  }

  return max_profit;
}
