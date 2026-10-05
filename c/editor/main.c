#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *fp = fopen(argv[1], "r");

  unsigned char buffer[1024];
  int count = fread(buffer, 1, 1024, fp);

  fclose(fp);

  return 0;
}
