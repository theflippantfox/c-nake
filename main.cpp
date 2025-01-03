#include <iostream>
#include <vector>

struct Cords {
  int x, y;
};

struct Snake {
  Cords head;
  std::vector<Cords> body;
} snake;

Cords food;
bool isFood = 0;

void gotoCords(int x, int y) {}

void growSnake(int x, int y) {
  Cords bodyitem;
  bodyitem.x = x;
  bodyitem.y = y;
  snake.body.push_back(bodyitem);
}

void eatFood() {
  if (!isFood) {
    return;
  }

  if (snake.head.x == food.x && snake.head.y == food.y) {
    growSnake(food.x, food.y);
  }
}

void printBoard() {}

void printSnake() {
  gotoCords(snake.head.x, snake.head.y); // Goto the cordinates of snake head
  std::cout << "@";                      // Print @ for head

  // If snake does not have any body then return
  if (!snake.body.size()) {
    std::cout << "No Body :(";
    return;
  }

  // If snake has a body then print *
  for (int i = 0; i < snake.body.size(); i++) {
    gotoCords(snake.body[i].x, snake.body[i].y);
    std::cout << "*";
  }
}

void runGame() {
  growSnake(2, 3);
  growSnake(3, 3);
  growSnake(4, 3);
  growSnake(5, 3);
  printSnake();
}

int main() {
  runGame();
  return 0;
}
