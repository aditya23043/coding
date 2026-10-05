#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define LINE_MAX 2048

typedef struct _TASKS {
    char **array;
    int index;
} s_TASKS;

int main(int argc, char **argv) {

    int selected_index_ncur = 0;
    s_TASKS tasks;
    tasks.array = malloc(MAX_TASKS*sizeof(char*));
    tasks.index = 0;

    initscr();
    noecho();
    curs_set(0);

    char content[LINE_MAX];

    if (argc != 2) {
        printf("Usage: ./a.out <file>\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Cannot open file!\n");
        return -1;
    }

    while (fgets(content, LINE_MAX, fp)) {
        tasks.array[tasks.index] = malloc(LINE_MAX*sizeof(char));
        strncpy(tasks.array[tasks.index], content, LINE_MAX);
        if (tasks.index == MAX_TASKS - 1) {
            break;
        }
        tasks.index++;
    }

    while (true) {

        for(int i = 0; i <= tasks.index; i++){
            if (i == selected_index_ncur)
                attron(A_STANDOUT);
            printw("%s", tasks.array[i]);
            if (i == selected_index_ncur)
                attroff(A_STANDOUT);
            refresh();
        }

        char inp = getch();
        if (inp == 'q') {
            clear();
            break;
        } else if (inp == 'j') {
            if (selected_index_ncur == tasks.index) {
                selected_index_ncur = 0;
            } else {
                selected_index_ncur++;
            }
        } else if (inp == 'k') {
            if (selected_index_ncur == 0) {
                selected_index_ncur = tasks.index;
            } else {
                selected_index_ncur--;
            }
        }
        clear();
    }

    endwin();

    for (int i = 0; i <= tasks.index; i++) {
        free(tasks.array[i]);
    }
    free(tasks.array);

    return 0;
}
