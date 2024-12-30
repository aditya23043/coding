#include <ncurses.h>

int main(int argc, char *argv[]) {

  int key;
  int x;
  int y;

  initscr();
  // enables the arrow keys
  keypad(stdscr, true);
  // does not print stuff we input using getch
  noecho();

  x = 5;
  y = 5;

  while (key != 'q') {

    clear();
    move(0, 0);
    printw("Press arrow keys and exit by pressing: q");

    move(y, x);
    printw("I");

    refresh();

    key = getch();
    if (key == KEY_LEFT || key == 'h') {
      x -= 2;
      if (x < 0) {
        x = 0;
      }
    }
    if (key == KEY_RIGHT || key == 'l') {
      x += 2;
    }
    if (key == KEY_UP || key == 'k') {
      y -= 2;
      if (y < 0) {
        y = 0;
      }
    }
    if (key == KEY_DOWN || key == 'j') {
      y += 2;
    }
  }

  endwin();
  return 0;
}
