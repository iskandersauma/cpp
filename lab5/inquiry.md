##Lab 5

### Lambda expression and smart pointers: Questions
####What is a capture list in lambda expression?
It defines what we can use outside of a function body. Captures are by default const.
####What does & inside mean inside the parameter list?
It means the parameter is given as a reference.
####When could capturing data by reference [&] be useful?
It allows the use of outside variables as reference which can be useful if we want to access something besides the input parameter.
####What does {4} in the code below do?
####A* p = new A {4};
In this case, it creates a pointer p that is an A construct where the data value is 4.
####Why is it a compile error to call foo with a unique_ptr without a move? foo(pa);
Because it goes out of scope without move and disposes the pointer which is where the error occurs.
####Was there ever a memory leak when calling foo2 with a shared pointer?
No, it worked fine with and without a move function.
####What is the use of a weak_ptr?
It provides access to one or more objects own by a shared_pointer.
####How do you creare a unique_ptr with a special deleter?
unique_ptr<B, function<void(B*)> > pb1(new_constructor_here,  lambda_here)  
lambda_here is the lambda constructor that is the special deleter.
####What is decltype?
It's a function used to specify a datatype. It returns a datatype.
####What is std::function?
It is a function used to declare lambda functions
####Whay did you learn in this assignment?
I learned how lambda expressions and smart pointers work. Though, this was only a simple introduction and I have a lot to learn about it.

###Watermanager: Questions
####What is [this] in the lambda sent to the condition_variable's wait-method? Why is [this] needed?
"This" referes to the watermanager which is needed to get the GnusInside/HyenasInside variable. Without it we will not be able to check the condition.
####Why is the lock a variable? What happens when th variable goes out of scope?
We use a variable so that we can hold several lock at the same time and then release when the condition is met.
####What is the difference between unique_lock and lock_guard?
Unique_lock can be locked and unlocked several times while lock_guard can be locked once untill destruction which is when it unlocks.
####Do the intefers hyenasInside, gnusInside need to be atomic?
No, only integer can suffice.
####Describe how .wait and .notifyall() work. Is any call blocking, and what does blocking mean?
Wait blocks untill the condition variable is meets it condition. Notifyall updates the threads waiting for the same condition to be met. Blocking is when the code is stoped from executing the rest of the code untill a condition is met which is what happens with wait.
####Write code that iterates over an unordered_map and prints each key and value.
unordered_map<string, int> map; 
map["first"] = 10;  
map["second"] = 20; 
map["third"] = 30;  
for(auto x: map)    
cout<< x.first << " " <<x.second << endl;
####When prining an unordered_map, why is the items not printed in the order they were inserted?
Because the order is depended on the hash value they get when inserted which can create any order.
####In what order would the items be printed if a map was used instead of an unordered_map?
They are printed in the order they are inserted.
####How did you implement turnoing on/off trace outputs? Compile time, runtime or both? Ellaborate over your decision.
I used neither. I could implement a bool variable called output where I decide if the program should print anything. There is no need for compile time or runtime since the codes do not run forever.
####What information did you print out in trace output from the watercave? Ellaborate over your decision
The id of the animal, what they are doing (enter/exit), how many of each are in the water cave and when they are thirsty. This makes it easier to track the motion of each thirsty animal.
####Do you prefer initializing your thread with a function or function object (functor)?
I used a functor to define the thread. (assumed they meant thread as in thread::id)















