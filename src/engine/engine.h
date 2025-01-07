#ifndef ENGINE_H
#define ENGINE_H

#include <ncurses.h>

typedef struct {
  void (*init)();
  void (*update)(int key);
  void (*render)();
  void (*cleanup)();
} Game;

extern int game_over;

void engine_run(Game *game);
void engine_inti();
void engine_cleanup();

#endif // !ENGINE_H
