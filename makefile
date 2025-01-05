# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = -lncurses

# Paths
SRCS = src/*/*.c
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
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf bin/
	@mkdir -p bin

# Build the executable from scratch
build: clean $(EXEC)

# Run the game
run: build
	clear
	./$(EXEC)

.PHONY: all clean build run
