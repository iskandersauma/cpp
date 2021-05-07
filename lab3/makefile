#include <iostream>
CC =g++ -std=c++11
sanitize = -fsanitize=leak


bintree: bintree.cpp bintree.h
	$(CC) $(sanitize) bintree.cpp -o bintree.out

tests: bintree.cpp bintree.h test_cxx.cpp
	cxxtestgen --error-printer -o generatedTest.cpp test_cxx.cpp
	$(CC) -o runner.out generatedTest.cpp
	./runner.out
balance: bintree.cpp bintree.h testbalance.cpp
	$(CC) testbalance.cpp -o bal.out
	./bal.out
