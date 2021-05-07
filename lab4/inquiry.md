##Lab4 inquiry

###Questions
####How many methods/functions have you implemented?
I have implemented 34 methods and functions including the operators.
####How many methods/functions have you tested?
I tested about 23 of these methods/functions. Some of them are similar enough to skip doing a seperate test for.
####Why should (some?) constructors be explicit? Explain with a code example
So that we cannot initiate a matrix by writing
Matrix<int> = 1;
####What is the benefit of a move-constructor? Explain with a code
We use it to initiate a rvalue. For example.
Matrix(mat); where mat is an rvalue 
####Describe how you manage memory when resizing. When do you need to resize?
I resized, for example, when I inserted a new row. What I did was to save all the values in a new list, deleted the old one and created a new empty list where I copy over all the old values in the right index.
####Why do you need to implement a const-version of the accessor operator?
So the function do not modify something in the class.
####If you type define the return type of begin/end as iterators is it possible to call std::sort() to sort your matrix?
Yes, it would be possible. There are many kinds of iterators that can be used to implement sort().
####What kind of iterator is begin/end?
They are iterators that return the address of the first and last index which implies that it is an bidirectional iterator.
####What other kind of iterators are there? Is there any you would like to implement?
There are quite many. Next, previous,inserter, advance, input, output, forward, random-access and bidirectional to start.
####What was the hardest to implement in this assignment?
Chaining and istream. I got stuck on these parts for a while.
####What did you learn from this assignment?
I got a deeper understanding of references, pointer and constructors.