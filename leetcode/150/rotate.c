#include <stdio.h>
#include <stdlib.h>

void rotate_2(int *nums, int numsSize, int k) {
  if (numsSize < 2) {
    return;
  }

  int final[numsSize];
  int index;

  for (int i = 0; i < numsSize; i++) {
    if (i - k < 0) {
      index = numsSize - k + i;
    } else {
      index = i - k;
    }
    final[i] = nums[index];
  }

  for (int i = 0; i < numsSize; i++) {
    nums[i] = final[i];
  }
}

void rotate(int *nums, int numsSize, int k) {
  if (k > numsSize) {

    for (int i = 0; i < k; i++) {
      rotate_2(nums, numsSize, 1);
    }
  } else {
    rotate_2(nums, numsSize, k);
  }
}

int main(int argc, char **argv) {

  /* int nums[] = {-1, -100, 3, 99}; */
  int nums[] = {1, 2};
  /* int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; */
  rotate(nums, sizeof(nums) / sizeof(nums[0]), 3);
  for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}
