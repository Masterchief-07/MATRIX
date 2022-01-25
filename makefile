test: main.cpp
	g++-11 $^ -std=c++17 -Wall -o $@

all: test

clean:
	rm -f  Test Matrix.o

