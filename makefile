clean:
	rm -rf bin/

build: clean
	mkdir bin/
	g++ main.cpp -o bin/snake

run: build
	clear
	./bin/snake
