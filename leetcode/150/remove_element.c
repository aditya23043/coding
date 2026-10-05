#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int removeElement(int *nums, int numsSize, int val) {
  int temp;
  int k;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == val) {
      nums[i] = INT_MAX;
    }
  }
  // sort: O(n^2) but ok
  for (int i = 0; i < numsSize; i++) {
    for (int j = i; j < numsSize; j++) {
      if (nums[i] > nums[j]) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
  }
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != INT_MAX)
      k++;
  }

  return k;
}

int main(int argc, char *argv[]) {
  int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
  removeElement(nums, sizeof(nums) / sizeof(int), 2);
}
