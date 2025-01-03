#include <ncurses.h>

void setupCurses() {
  initscr();            // Start ncurses mode
  timeout(0);           // Non-blocking input
  cbreak();             // Disable line buffering
  noecho();             // Don't echo input
  keypad(stdscr, TRUE); // Enable special keys
}

void cleanupCurses() {
  endwin(); // End ncurses mode
}
