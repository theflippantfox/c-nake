#ifndef GAME_H
#define GAME_H

#include <vector>

struct Cords {
  int x, y;
};

struct Snake {
  Cords head;
  std::vector<Cords> body;
};

extern int boardHeight;
extern int boardWidth;

extern Cords food;
extern bool isFood;
extern bool isGameOver;

enum Direction { UP, DOWN, LEFT, RIGHT };
extern Direction currentDirection;

void growSnake(int x, int y);
void createFoodItem();
void eatFood();
void checkGameOver();
void moveSnake();
void initGame();
void runGame();

#endif // GAME_H
