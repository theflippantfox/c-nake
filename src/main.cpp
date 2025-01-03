#include "board.h"
#include "game.h"
#include "input.h"
#include <chrono>
#include <iostream>
#include <ncurses.h>
#include <thread>

int main() {
  // Hide the cursor
  std::cout << "\u001b[?25l";

  setupCurses();

  initGame();
  runGame();

  cleanupCurses();

  // Show the cursor
  std::cout << "\u001b[?25h";
  return 0;
}
