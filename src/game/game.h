#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>

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

void snake_init();
void snake_update();
void snake_render();
void snake_cleanup();

#endif // !GAME_H
