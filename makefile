test: main.cpp
	g++ $^ -Og -g -std=c++17 -Wall -Wextra -Wpedantic -Wconversion -o $@

all: test

clean:
	rm -f  Test Matrix.o

