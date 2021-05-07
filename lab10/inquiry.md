##Lab 10
###Questions:
####How would you have solved the command line parser without using an unordered_set with commands?
There are several methods one could use but not as efficient. You can use if statements to compare the first word to a function for example or use a vector. Ordered map can also be utilized. 

####How would you prefer implementing a command line parser?
Using stdin is the easiest method for this.

####What global variables did you use?
I used a few. Two for objects and three characters which is a total of five.

####Describe how you solved ownership of items? Where are the items contained?
I solved the ownership problem by assigning an item to a person and for the item the owner. Since I wanted to keep things simple I used only string methods for this but in an optimal setting, using pointers is better. Having a parameter from a character pointing to the object address. This is just an example on how to do it.

####What did you learn from this assignment?
You can have a function as a value in hashmaps and call the function when the "value" is returned.