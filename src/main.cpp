#include "board.h"
#include "game.h"
#include "input.h"
#include <chrono>
#include <iostream>
#include <ncurses.h>
#include <thread>

extern void setupCurses();
extern void cleanupCurses();

int main() {
  // Hide the cursor on the terminal
  std::cout << "\u001b[?25l";

  setupCurses();

  initGame();
  runGame();

  cleanupCurses();

  // Show the cursor again
  std::cout << "\u001b[?25h";
  return 0;
}
