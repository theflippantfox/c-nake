# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = -lncurses

# Paths
SRCS = src/main.cpp src/board.cpp src/game.cpp src/input.cpp src/curses.cpp # Explicitly list the source files
OBJS = $(SRCS:src/%.cpp=bin/%.o)

# Executable name
EXEC = bin/snake_game

# Default target: Build and run the game
all: run

# Build the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Create object files
bin/%.o: src/%.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf bin/

# Build the executable from scratch
build: clean $(EXEC)

# Run the game
run: build
	clear
	./$(EXEC)

.PHONY: all clean build run
