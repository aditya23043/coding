#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize) {
  int temp = 0;
  int index = 0;
  int k = 0;
  for (int i = 0; i < numsSize; i++) {
    if (i < numsSize - 1) {
      if (nums[i] == nums[i + 1]) {
        temp = nums[i];
        if (i < numsSize - 2) {
          index = i + 2;
          while (nums[index] == temp) {
            nums[index] = INT_MAX;
            index++;
          }
        }
      }
    }
  }
  // bubble sort
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
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
  int nums[] = {1, 1, 1};
  int k = removeDuplicates(nums, sizeof(nums) / sizeof(int));
  printf("%d\n", k);
  return 0;
}
