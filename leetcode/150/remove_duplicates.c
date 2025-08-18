#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int removeDuplicates(int *nums, int numsSize) {
  int k = 0;
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] == nums[j]) {
        nums[j] = INT_MAX;
      }
      if (nums[i] > nums[j]) {
        swap(&nums[i], &nums[j]);
      }
    }
  }
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != INT_MAX) {
      k++;
    }
  }
  printf("%d\n", k);
  return k;
}

int main(int argc, char *argv[]) {

  int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  removeDuplicates(nums, sizeof(nums) / sizeof(int));
  return 0;
}
