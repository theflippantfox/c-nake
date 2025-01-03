#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int boardHeight = 1;
int boardWidth = 1;

struct Cords {
  int x, y;
};

struct Snake {
  Cords head;
  std::vector<Cords> body;
} snake;

Cords food;
bool isFood = 0;

// Goto the provided cordinates on the terminal
void gotoCords(int x, int y) {}

// Add length to snake body based on certain events
void growSnake(int x, int y) {
  Cords bodyitem;
  bodyitem.x = x;
  bodyitem.y = y;
  snake.body.push_back(bodyitem);
}

// Creates a food item at a random location
void createFoodItem() {
  std::srand(std::time(0));           // Seed random number generator
  food.x = std::rand() % boardHeight; // Replace 20 with board width
  food.y = std::rand() % boardWidth;  // Replace 10 with board height
  isFood = 1;
}

// Checks if the snake has eaten the food
void eatFood() {
  if (!isFood) {
    return;
  }

  if (snake.head.x == food.x && snake.head.y == food.y) {
    growSnake(food.x, food.y);
  }
}

// Print the board (level)
void printBoard() {}

// Print the snake head and body
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

// The core game funtion
void runGame() {

  // TODO: Implement game loop
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
