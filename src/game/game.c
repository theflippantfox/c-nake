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
}

void snake_update() {
  Snake.head.x++;
  if (Snake.head.x > window_width)
    Snake.head.x = 0;
}

void snake_render() {
  print_border();

  mvprintw(Snake.head.y, Snake.head.x, "O");
}

void snake_cleanup() {
  // TODO:
}
