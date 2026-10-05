#include <stdio.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: ./a.out <file>");
        return -1;
    }

    return 0;
}
