#include "board.h"
#include "game.h"
#include <iostream>

void clearScreen() { std::cout << "\u001b[2J"; }

void gotoCords(int x, int y) { std::cout << "\u001b[" << y << ";" << x << "H"; }

void printBoard() {
  clearScreen();

  for (int x = 0; x <= boardWidth; ++x) {
    gotoCords(x, 0);
    std::cout << "#";
  }

  for (int y = 1; y < boardHeight; ++y) {
    gotoCords(0, y);
    std::cout << "#";
    gotoCords(boardWidth, y);
    std::cout << "#";
  }

  for (int x = 0; x <= boardWidth; ++x) {
    gotoCords(x, boardHeight);
    std::cout << "#";
  }
}

void printSnake() {
  gotoCords(snake.head.x, snake.head.y);
  std::cout << "@";

  for (std::vector<Cords>::size_type i = 0; i < snake.body.size(); i++) {
    gotoCords(snake.body[i].x, snake.body[i].y);
    std::cout << "*";
  }
}
