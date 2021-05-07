CC = g++ -std=c++11
sanitize = -fsanitize=leak
FLAGS = -g -Wall -pedantic

lambda: lambda.cpp
	$(CC) $(sanitize) lambda.cpp -o lambda.out
	./lambda.out
valgrind: lambda.cpp
	$(CC) $(FLAGS) lambda.cpp -o lambda.out
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./lambda.out
watermanager: watermanager.cpp
	$(CC) $(sanitize) watermanager.cpp -o watermanager.out
	./watermanager.out
