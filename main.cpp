#include <iostream>
#include <vector>

struct Cords {
  int x, y;
};

struct Snake {
  Cords head;
  std::vector<Cords> body;
} snake;

void print_board() {}

void print_snake() {
  if (snake.body.size()) {
    std::cout << "Body!!!";
  } else {
    std::cout << "No Body :(";
  }
}

int main() {
  print_snake();
  return 0;
}
