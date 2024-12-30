#include <ncurses.h>

int main(int argc, char *argv[]) {

  int x, y;
  initscr();
  clear();

  getyx(stdscr, y, x);
  printw("x = %d\ny = %d", x, y);
  refresh();

  y = 5;
  x = 10;

  move(y, x);
  printw("Moved 10 chars over and 5 lines down!");

  getch();
  endwin();

  return 0;
}
