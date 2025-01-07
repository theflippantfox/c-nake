#include "engine.h"

void engine_init() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
}

void engine_run(Game *game) {
  clear();

  engine_init();
  game->init();

  while (!game_over) {
    int ch = getch();

    game->update(ch);
    game->render();
    refresh();
    napms(200);
  }

  game->cleanup();
  engine_cleanup();
}

void engine_cleanup() { endwin(); }
