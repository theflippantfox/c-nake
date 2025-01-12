#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

extern int window_width;
extern int window_height;
extern int game_over;

struct _Cords {
  int x;
  int y;
};

struct _Snake {
  _Cords head;
  _Cords body[500];
  int length;
};

struct _Direction {
  int x;
  int y;
};

void init_colors();
void food_init();
void food_render();
void print_border();
void check_collision();
void handle_input();
void check_food_eaten();
void move_snake();
void clear_board();

void init();
void update(int key);
void render();
void cleanup();

#endif // !GAME_H
