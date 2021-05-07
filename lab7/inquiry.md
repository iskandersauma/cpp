##Lab 7
###Questions:
####In what order are the mapitems printed?
Mapitems are usually printed in the order they are given,but using rbegin() and rend() returns them in order of largest to smallest.
####What is the underlying data structure std::map uses?
Its a selfbalancing tree
####Which is the first knapsackweight where the second greedy solution is better than the first?
It occurs when knapsacksize is 30
####What is the difference between a std::set and a std::map?
Set stores only keys while map store key values pairs. Also, set ordered key values according so smallest value to largest, while map prints in the order the values are given.
####What is the difference between a std::set and a std::unordered_map?
Same as previous question, set uses key values and unordered map in key value pairs. Set orders key value from smallest to largest while in unordered_map, it does in random since it depends on the hash value.
####Find five knapsack values where the optimal solution is equal to greedy solution 1.
The optimal knapsack sizes are 13, 14, 15, 16 and 17 which gives the knapsack values 21, 22, 23, 24 and 28 respectively.
####Find five knapsack values where the optimal solution is equal to greedy solution 2.
The optimal knapsack sizes are 13, 26, 39, 52 and 65 which gives the knapsack values 21, 42, 63, 84 and 105 respectively. 