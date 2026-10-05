#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

  unsigned int seed = time(0);

  printf("%d\n", rand_r(&seed));

  return 0;
}
