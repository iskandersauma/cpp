##Lab3
###Questions
####If the signature of insert was changed like below, how would that affect your code?
####Node * insert(Node* p, int key, double value);
The code would mostly remain the same, the difference would be that I would have to return a node/tree pointer.
####Which of the two insert variants would you prefer? Motivate.
The one I use. The method is to insert a node in a bintree but there is still merit in returning the tree of the node
####How that your are able to pass a value, such as 17, to a const int& parameter?
A temporary variable of the value is created and a reference of the value is passed to the function as a parameter.
####How do you check if two object are equal of they only have operator< and not operator==?
You can check if object1 is bigger than object2 and object2 is bigger than object1. If both are wrong the only thing that remains is that they are equal.
####Does a<b and !(b<a) compare the same thing?
No, since !(b<a) is the same as a<=b.
####What was the hardes to implement in this assignment?
Deleting a node in the bintree.
####What did you learn from this assignment?
How pointers work.
