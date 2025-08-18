#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize) {
  int max_prof = 0;
  for (int i = 0; i < pricesSize; i++) {
    for (int j = i + 1; j < pricesSize; j++) {
      if (prices[j] - prices[i] > max_prof) {
        max_prof = prices[j] - prices[i];
      }
    }
  }
  return max_prof;
}

int main(int argc, char **argv) {

  int prices[] = {3, 2, 6, 5, 0, 3};
  maxProfit(prices, sizeof(prices) / sizeof(int));

  return 0;
}
