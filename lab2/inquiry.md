##Lab2
###Questions
####What is the benefit of having a conversion constructor?
It allows us to create objects without specifying the parameters of the construct.
####WHich of your class methods or non member functions returns a copy?
We use operator= and operator<<,operator-, operator+ for returning a copy.
####Which of your class methods or non member functions returns a reference?
The operator= and non member mathematical calculations returns a reference.
####How many tests do you need at minimum to test the abs function?
Only one. Sqrt is a built in function and we can easily determine what value abs functions should return to see if it is correct.
####Were there any constructor calls in the above list that suprised you?
No, I consider those that I implemented to be necessary depending on what I know.
####Describe and motivate how your implementation of operator= works.
In short, I take in a complex referenced complex construct, copy the complex and reell value in the construct and returned it as referenced. 
####What constructor/functions are called when writing the statement Complex k = 3+5_i?
Operator""_i, operator+ and copy constructor.
####Describe and motivate how your implementation of operator += -= /= *= works.
I use the mathematical derivation of each operator and return a referenced complex constructor.
####What is the rule of three in c++. Look it up in course book or on the web.
It refereces that a class should include a destructor, copy constructor and a copy assignment operator.
####Do you need to explicitly define and implement the copy-constructor in this assignment?
No, it is enough to use copy assignment operator and conversion constructor.
####The literal i has an underscore before it. Why is that? Look it up in the c++11 draft section 17.6.4.3.5 and explain. Has there been any changes regarding this matter in the new c++17 draft?
It is used for reserved literal suffix and it is still used un c++17.
####What was the hardest part (or parts) in this assignment?
Regex, I was thouroughly confused how it worked.




