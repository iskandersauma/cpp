##Lab 9
###Questions:
####Are there any benefits using template meta programming to calculate prime numbers in compile time compared to the program that generated c++ code for prime numbers?
There are several. Compiler don't get stuck in infinite recurrsion and can utilize static_assert for testing for example.

####Can you calculate and assign an array of prime numbers in compile time using constexpr ?
Yes

####Can the compiler evaluate if-statements in compile time using constexpr?
yes

####What did you learn from this assignment?
Alot of backwards recursive thinking