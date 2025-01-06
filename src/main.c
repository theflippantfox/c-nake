#include "engine/engine.h"
#include "game/game.h"

int main() {
  Game snake_game = {.init = snake_init,
                     .update = snake_update,
                     .render = snake_render,
                     .cleanup = snake_cleanup};

  engine_run(&snake_game);
  return 0;
}
