#include <stdarg.h>
#include <stdio.h>

#define something(a, _, c) printf("%d", __LINE__);

int main(int argc, char *argv[]) {

  something(x, ->, x + 1);

  return 0;
}
