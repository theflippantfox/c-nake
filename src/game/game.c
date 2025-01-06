#include "game.h"
#include "../engine/engine.h"

void food_init() {
  srand(time(NULL));

  Food.x = rand() % (window_width - 2) + 1;
  Food.y = rand() % (window_height - 2) + 1;
}

void food_render() { mvprintw(Food.y, Food.x, "x"); }

void print_border() {
  for (int i = 0; i <= window_height; i++) {
    for (int j = 0; j <= window_width; j++) {
      if ((i == 0 || i == window_height) && (j == 0 || j == window_width)) {
        mvprintw(i, j, "+");
        continue;
      }

      if (i == 0 || i == window_height) {
        mvprintw(i, j, "=");
        continue;
      }

      if (i > 0 && (j == 0 || j == window_width)) {
        mvprintw(i, j, "|");
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
  food_render();

  mvprintw(Snake.head.y, Snake.head.x, "O");
}

void snake_cleanup() {
  // TODO:
}
