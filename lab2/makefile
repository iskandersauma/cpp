#include <iostream>
CC = g++ -std=c++11


test: test.cpp lab2.cpp
	cxxtestgen --error-printer -o generatedTest.cpp test.cpp
	$(CC) -o runner.out generatedTest.cpp
	./runner.out
complex: lab2.cpp
	$(CC) lab2.cpp -o lab2.out
