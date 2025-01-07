#include "game.h"
#include "../engine/engine.h"

int window_width = 120;
int window_height = 35;

int game_over = 0;

_Snake Snake;
_Cords Direction;
_Cords Food;

void init_colors() {
  if (has_colors()) {
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
  }
}

void food_init() {
  Food.x = rand() % (window_width - 2) + 1;
  Food.y = rand() % (window_height - 2) + 1;
}

void print_border() {
  attron(COLOR_PAIR(1));
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
  attroff(COLOR_PAIR(1));
}

void food_render() { mvprintw(Food.y, Food.x, "x"); }

void check_collision() {
  if (Snake.head.x <= 0 || Snake.head.x >= window_width || Snake.head.y <= 0 ||
      Snake.head.y >= window_height) {
    game_over = 1;
  }
}

void handle_input(int ch) {
  switch (ch) {
  case KEY_UP:
    if (Direction.y != 1) {
      Direction.x = 0;
      Direction.y = -1;
    }
    break;

  case KEY_DOWN:
    if (Direction.y != -1) {
      Direction.x = 0;
      Direction.y = 1;
    }
    break;

  case KEY_LEFT:
    if (Direction.x != 1) {
      Direction.x = -1;
      Direction.y = 0;
    }
    break;

  case KEY_RIGHT:
    if (Direction.x != -1) {
      Direction.x = 1;
      Direction.y = 0;
    }
    break;

  case 'q':
    game_over = 1;
    break;
  }
}

void update(int key) {
  if (key != ERR) {
    handle_input(key);
  }

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

void render() {
  clear_board();
  food_render();

  mvprintw(Snake.head.y, Snake.head.x, "O");
  /* for (int i = 0; i < Snake.body.length; i++) { */
  /*   mvprintw(Snake.body[i].y, Snake.body[i].x, "x"); */
  /* } */
}

void init() {
  srand(time(NULL));

  Snake.head.x = window_width / 2;
  Snake.head.y = window_height / 2;

  Snake.body[0].x = (window_width / 2) - 1;
  Snake.body[0].y = (window_height / 2);

  Direction.x = 1;
  Direction.y = 0;

  food_init();

  init_colors();
  print_border();
}

void cleanup() {
  // TODO:
}
