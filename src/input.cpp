#include "input.h"
#include "game.h"
#include <ncurses.h>

void handleInput() {
  int ch = getch();
  if (ch != ERR) {
    switch (ch) {
    case KEY_UP:
      if (currentDirection != DOWN) {
        currentDirection = UP;
      }
      break;
    case KEY_DOWN:
      if (currentDirection != UP) {
        currentDirection = DOWN;
      }
      break;
    case KEY_LEFT:
      if (currentDirection != RIGHT) {
        currentDirection = LEFT;
      }
      break;
    case KEY_RIGHT:
      if (currentDirection != LEFT) {
        currentDirection = RIGHT;
      }
      break;
    case 'q':
      isGameOver = 1;
      break;
    default:
      break;
    }
  }
}
