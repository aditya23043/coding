#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define STDOUT 1
#define STDIN 1

int main(int argc, char *argv[]) {

  char command[256];

  for (;;) {
    write(STDOUT, "  $ ", 4);
    int count = read(STDIN, command, 256);

    printf("%s", command);
    if (strcmp(command, "exit\n") == 0) {
      printf("%s", "EXIT BRUH");
      return 0;
    }

    // <command>\n -> <command>\0
    command[count - 1] = 0;

    pid_t fork_result = fork();

    // child
    if (fork_result == 0) {
      execve(command, 0, 0);
      break;
    }
    // in the parent, we want to wait unitl the child has finished
    else {
      siginfo_t info;
      waitid(P_ALL, 0, &info, WEXITED);
    }
  }

  return 0;
}
