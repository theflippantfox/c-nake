#include "game.h"
#include "../engine/engine.h"

static int x = 10, y = 10;

void snake_init() {
  x = 10;
  y = 10;
}

void snake_update() {
  x++;
  if (x > COLS)
    x = 0;
}

void snake_render() { mvprintw(y, x, "O"); }

void snake_cleanup() {
  // TODO:
}
