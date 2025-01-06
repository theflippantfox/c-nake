#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct _Cords {
  int x;
  int y;
};

struct _Snake {
  _Cords head;
  _Cords body[];
};

struct _Direction {
  int x;
  int y;
};

extern int window_width;
extern int window_height;

void snake_init();
void snake_update();
void snake_render();
void snake_cleanup();

#endif // !GAME_H
