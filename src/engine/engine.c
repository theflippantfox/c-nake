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
  engine_init();
  game->init();

  while (1) {
    clear();
    game->update();
    game->render();
    refresh();
    napms(100);
  }

  game->cleanup();
  engine_cleanup();
}

void engine_cleanup() { endwin(); }
