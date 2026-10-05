#include <ncurses.h>

int main(int argc, char *argv[]) {

  char letter;

  initscr();
  printw("Press any key");
  refresh();

  letter = getch();
  clear();
  printw("You pushed: %c", letter);
  refresh();

  getch();

  endwin();

  return 0;
}
