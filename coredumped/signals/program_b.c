#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: ./bin <Process ID>");
        return -1;
    }

    kill(atoi(argv[1]), SIGUSR1);

    printf("Sent SIGUSR1 to process: %s", argv[1]);

    return 0;
}
