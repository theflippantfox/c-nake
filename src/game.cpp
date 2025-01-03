#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int boardHeight = 20;
int boardWidth = 40;

Cords food;
bool isFood = 0;
bool isGameOver = 0;

Direction currentDirection = RIGHT;
Snake snake;

void growSnake(int x, int y) {
  Cords bodyitem;
  bodyitem.x = x;
  bodyitem.y = y;
  snake.body.push_back(bodyitem);
}

void createFoodItem() {
  food.x = std::rand() % boardWidth;
  food.y = std::rand() % boardHeight;
  isFood = 1;
}

void eatFood() {
  if (!isFood) {
    return;
  }

  if (snake.head.x == food.x && snake.head.y == food.y) {
    growSnake(food.x, food.y);
  }
}

void checkGameOver() {
  if (snake.head.x <= 0 || snake.head.x >= boardWidth || snake.head.y <= 0 ||
      snake.head.y >= boardHeight) {
    isGameOver = 1;
  }

  for (int i = 0; i < snake.body.size(); i++) {
    if (snake.head.x == snake.body[i].x && snake.head.y == snake.body[i].y) {
      isGameOver = 1;
    }
  }
}

void moveSnake() {
  for (int i = snake.body.size() - 1; i > 0; --i) {
    snake.body[i] = snake.body[i - 1];
  }

  if (!snake.body.empty()) {
    snake.body[0] = snake.head;
  }

  switch (currentDirection) {
  case UP:
    snake.head.y--;
    break;
  case DOWN:
    snake.head.y++;
    break;
  case LEFT:
    snake.head.x--;
    break;
  case RIGHT:
    snake.head.x++;
    break;
  }
}

void initGame() {
  std::srand(std::time(0)); // Seed random number generator for food generation
  snake.head = {boardWidth / 2, boardHeight / 2};
  createFoodItem();
}

void runGame() {
  while (!isGameOver) {
    moveSnake();
    eatFood();
    checkGameOver();
  }
}
