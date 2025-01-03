#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

struct Cords {
  int x, y;
};

struct Snake {
  Cords head;
  std::vector<Cords> body;
} snake;

int boardHeight = 32;
int boardWidth = 64;

Cords food;
bool isFood = 0;
bool isGameOver = 0;

// Clear terminal screen
void clearScreen() { std::cout << "\u001b[2J"; }

// Goto the provided cordinates on the terminal
void gotoCords(int x, int y) { std::cout << "\u001b[" << y << ";" << x << "H"; }

// Add length to snake body based on certain events
void growSnake(int x, int y) {
  Cords bodyitem;
  bodyitem.x = x;
  bodyitem.y = y;
  snake.body.push_back(bodyitem);
}

// Creates a food item at a random location
void createFoodItem() {
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
void printBoard() {
  // Clear the screen
  clearScreen();

  // Draw the top boundary
  for (int x = 0; x <= boardWidth; ++x) {
    gotoCords(x, 0); // Top row (y = 0)
    std::cout << "#";
  }

  // Draw the bottom boundary
  for (int x = 0; x <= boardWidth; ++x) {
    gotoCords(x, boardHeight); // Bottom row (y = boardHeight)
    std::cout << "#";
  }

  // Draw the left and right boundaries
  for (int y = 1; y < boardHeight; ++y) {
    gotoCords(0, y); // Left column (x = 0)
    std::cout << "#";
    gotoCords(boardWidth, y); // Right column (x = boardWidth)
    std::cout << "#";
  }
}

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
  std::srand(std::time(0)); // Seed random number generator for food generation

  // TODO: Implement game loop

  while (!isGameOver) {

    printBoard();
  }
}

int main() {
  runGame();
  return 0;
}
