#include <ncurses.h>

int Engine() {
  initscr();
  mvprintw(5, 5, "Hello, World!");
  endwin();
  getch();
  return 0;
}
