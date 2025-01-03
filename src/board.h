// board.h
#ifndef BOARD_H
#define BOARD_H

#include "game.h" // Include the Snake struct definition

extern Snake snake; // Declare the snake variable as external

void printBoard();
void printSnake();
void clearScreen();
void gotoCords(int x, int y);

#endif
