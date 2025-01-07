#include "engine/engine.h"
#include "game/game.h"

int main() {
  Game snake_game = {
      .init = init, .update = update, .render = render, .cleanup = cleanup};

  engine_run(&snake_game);
  return 0;
}
