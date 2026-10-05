#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int len = 10;
  int *arr = malloc(sizeof(int) * len);
  for (int i = 0; i <= len; i++) {
    arr[i] = 5;
  }

  free(arr);
}
