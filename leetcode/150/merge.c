#include <stdio.h>
#include <stdlib.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  int i = 0;
  int j = 0;
  int index = 0;
  int *final = malloc(sizeof(int) * (m + n));
  while (i < m && j < n) {
    if (nums1[i] < nums2[j]) {
      final[index++] = nums1[i++];
    } else {
      final[index++] = nums2[j++];
    }
  }
  while (i < m) {
    final[index++] = nums1[i++];
  }
  while (j < n) {
    final[index++] = nums2[j++];
  }

  for (int i = 0; i < (m + n); i++) {
    nums1[i] = final[i];
  }

  free(final);
}

int main(int argc, char *argv[]) {
  int nums1[] = {1, 2, 3, 0, 0, 0};
  int nums2[] = {2, 5, 6};
  merge(nums1, 6, 3, nums2, 6, 3);
}
