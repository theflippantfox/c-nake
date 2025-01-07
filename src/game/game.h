#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

extern const int window_width;
extern const int window_height;

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

void init();
void update(int key);
void render();
void cleanup();

#endif // !GAME_H
