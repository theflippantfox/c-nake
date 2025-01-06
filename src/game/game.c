#include "game.h"
#include "../engine/engine.h"

int window_width = 120;
int window_height = 35;

int game_over = 0;

_Snake Snake;
_Cords Direction;
_Cords Food;

void food_init() {
  Food.x = rand() % (window_width - 2) + 1;
  Food.y = rand() % (window_height - 2) + 1;
}

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

void food_render() { mvprintw(Food.y, Food.x, "x"); }

void check_collision() {
  if (Snake.head.x <= 0 || Snake.head.x >= window_width || Snake.head.y <= 0 ||
      Snake.head.y >= window_height) {
    game_over = 1;
  }
}

void snake_update() {
  Snake.head.x += Direction.x;
  Snake.head.y += Direction.y;

  check_collision();
}

void clear_board() {
  for (int y = 1; y < window_height; y++) {
    for (int x = 1; x < window_width; x++) {
      mvprintw(y, x, " ");
    }
  }
}

void snake_render() {
  clear_board();
  food_render();

  mvprintw(Snake.head.y, Snake.head.x, "O");
}

void snake_init() {
  srand(time(NULL));

  Snake.head.x = window_width / 2;
  Snake.head.y = window_height / 2;

  Direction.x = 1;
  Direction.y = 0;

  food_init();

  print_border();
}

void snake_cleanup() {
  // TODO:
}
