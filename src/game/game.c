#include "game.h"
#include "../engine/engine.h"

int window_width = 120;
int window_height = 35;

struct _Cords {
  int x;
  int y;
};

struct _Snake {
  _Cords head;
  _Cords body[];
} Snake;

struct _Direction {
  int x;
  int y;
} Direction;

_Cords Food;

void print_border() {
  for (int i = 0; i <= window_height; i++) {
    for (int j = 0; j <= window_width; j++) {
      if ((i == 0 || i == window_height) && (j == 0 || j == window_width)) {
        mvprintw(i, j, "+");
        continue;
      }

      if (i == 0) {
        mvprintw(i, j, "-");
        continue;
      }

      if (i > 0 && (j == 0 || j == window_width)) {
        mvprintw(i, j, "|");
        continue;
      }

      if (i == window_height) {
        mvprintw(i, j, "-");
        continue;
      }
    }
  }
}

void snake_init() {
  Snake.head.x = 10;
  Snake.head.y = 10;

  Direction.x = 1;
}

void snake_update() {
  Snake.head.x += Direction.x;
  Snake.head.y += Direction.y;
}

void snake_render() {
  print_border();

  mvprintw(Snake.head.y, Snake.head.x, "O");
}

void snake_cleanup() {
  // TODO:
}
