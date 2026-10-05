#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int id = fork();
  printf("something from ID: %d\n", id);
  if (id == 0) {
    printf("This is a child process!\n");
  } else {
    printf("This is the main process!\n");
  }

  return 0;
}
