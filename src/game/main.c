#include <stdio.h>

typedef struct _Cords {
  int x;
  int y;
};

typedef struct _Snake {
  _Cords head;
  _Cords body[];
} Snake;

typedef struct _Food {
  int x;
  int y;
} Food;

int main() { return 0; }
