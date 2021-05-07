##Lab1 inquiry

###g++ compiler questions
####Where can you find the manual to g++?
One good source for the manual can be found [here](https://gcc.gnu.org/onlinedocs/).
ALternatively, the commandline 'info g++' also works.
####What is the purpose of -Wall and -g when passed as arguments to g++?
-g: gives extra debugging information in "the operating system's native format.
-Wall: (with all) enable varnings about constructors some users consider questionable and avoidable.
#### Find and write down 4 other arguments tp g++ that you think might be useful and write a short motivation why you selected these specific 4 arguments.
-o:places output in a readable file
-c: compiles or assembles the source files
-help: gives comand line options.
-version: gives the version of the program
#### What is the difference between an object file, and an executeable?
An executeable is a file used for various operations or functions in a computer which cannot be read by a human.
An object file contains object code or "relocateable format machine code".
###Git questions
#### What does git show HEAD~:01/makefile show?
It show the previous added makefile.
#### What does git show HEAD:01/makefile show?
It shows the current added makefile
#### What does git show HEAD~~:01/makefile show?
It shows the two steps prior added makefile
#### What does the ~ in the previous git show commands mean?
It means a step prior to the current one. Severeal means several steps prior to the current one.
####Why can you not ommit 01 in the previous commands (i.e. git show HEAD~:makefile instead of git show HEAD~:01/makefile)?
Because it would lack a reference to where to place the added file.
####Sometimes you may need to do a git pull before you can do a git push. Hoe can that be?
If someone else has changed something in the files in git then you need to pull to have the updated versions. Then you can pull.
####What is the purpose of the .git_ignore file and why should *.o *.out *.exe be in this file when developing C++?
It specifies which intentionally untracked files git should ignore. They specify which files that can be ignored.
###Makefile questions
####If you invoke touch hello.cpp prior to invoking make, how many files were rebuilt?
2
####Why?
Because the commandline specify to update only that file. It is possble to uodate several files at the same time.
####Why do you think make checks the modification timestamp of the relevant files as par  of deciding what to do?
To check if the files are up-to-date.
####What is the difference between an implicit and explicit rule in a makefile?
Implicit rule tell make how to use "customary" techniques so that you don't have to specify them in detail.
Explicit rule specify the instructions that make must follow.
####What does $* mean inside a makefile?
it gives all the codes related to the variable written in $. For example, if c = g++ .. -o ... and we write $(c). If it compiles it will return c.
###Hello world questions
####What is the purpose of std::cout, std::cerr and std::clog, respectively?
cout gives output, cerr prints error and clog prints out logging (intended for logging)
####How does #include work?
It allowes the use of functions from other libraries. It is an import function.
###Debugging questions
####WHy does not powerof return the expected value (16), when invoked with 2 and 4?
My thought was that the error was in the for loop syntax because I changed it and it got the expected value.
####Why does not adding_a_decimal output 100,000?
It is because c++ saves the value of 0.1 as a binary and everytime we use it we get an error. Using it a million time we can see the error more clearly.
####Describe how weird.out is invoked by echo '3.1415'|./weird.out
It works as if echo read in the value that cin would want us to write on our own.
####Why does not y compare equal to 3.1415?
It is because they are using two different data types which saves the value in two different ways.
####Is there any difference in behavior if we compare y to 3.1415f,if so; why?
There is no difference because the f after the value because it is a suffix. In this case the f stands for float.
####Describe and motivate the recommended method to use when trying to determine if two floating-point values are equal.
You need you ensure not only the value is the same but how many digits they are using and which data type.
###Unit test questions
####Why is it important to test the boundary condition of an implementation, especially in the case of count_if_followed_by?
In the case of count_if_followed_by, it is important to test example the boundry of the array in case we use a array point that is not declared and getting errors. Or in the worst case, crashing the program.
####Describe how the testcase tests if a pointer is accessing an element outisde the range specified
It compares the length of the array and the amount of times we compare.
###class construction questions
####What constructors are invoked and when? List the corresponding lines and name the invoked constructor.
There are three constructors. One no parametric constructor in line 5, one with reference as parameter in line 9 and one with a pointer parameter in line 17.
####Will there be any temporaries created, if so; when?
No temporaries where created
####What will happen if we try t free a dynamically allocated array through delete p, instead of delete []p?
We will get an error since arrays have a specific code for deletion. 
###Valgrind questions
####Valgrind indicates that there is something wrong with complex.cpp; what, and why?
Complex.cpp has a leak and a few errors. The leak comes from a array that is not properly removed.
####Valgrind indicates that the program suffers from a few problems, which and why?
Same answer as the last question
It shows leaks and errors.
####If you comment out the entire if-block in foo, is there any difference in how much memory is leaked?
No, the array takes the same amount of memory to save. The memory space might be empty but it is still used.
####Why is it that the valgrind still issue diagnostics related to memory management?
Because when we are adding the last two lines the poiner v becomes disassociated from the variable. When this happens it is impossible to erase.




























