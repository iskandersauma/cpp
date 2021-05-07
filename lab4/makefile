#include <iostream>
CC = g++ -std=c++11
sanitize = -fsanitize=leak

matrix: matrix.cpp
	$(CC) $(sanitize) matrix.cpp -o matrix.out
	./matrix.out
test: matrix.cpp test.cpp
	cxxtestgen --error-printer -o generatedTest.cpp test.cpp
	$(CC) -o runner.out generatedTest.cpp
	./runner.out
