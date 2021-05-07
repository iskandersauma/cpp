#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "bintree.cpp"
using namespace std;

vector<int> create_test(int size){
  vector<int> vec(size);
  for(int i = 0; i<size; ++i){
    vec[i] = i;
  }
  shuffle(vec.begin(),vec.end(),default_random_engine(940325));
  return vec;
}

Node* create_tree(vector<int> vec){
  Node * tree = nullptr;
  for(int i = 0; i < vec.size(); i++){
    insert(tree, vec[i], vec[i]);
  }
  return tree;
}

double average_height(vector<int> fuckface){
  int sum = 0;
  for(int i = 0; i < fuckface.size(); i++){
    sum += fuckface[i];
  }
  return sum/fuckface.size();
}

int find_max_height(vector<int> lol){
  int max = 0;
  for(int i = 0; i <lol.size();i++){
    if(max < lol[i]){
      max = lol[i];
    }
  }
  return max;
}

int find_min_height(vector<int> lol){
  int min = 999999999;
  for(int i = 0; i < lol.size(); ++i){
    if(min > lol[i]){
      min = lol[i];
    }
  }
  return min;
}

double average(vector<vector<int>> lol){
  int diff = 0;
  for(int i = 0; i < lol.size();i++){
    diff += lol[0][i]-lol[1][i];
  }
  return diff/lol.size();
}

int find_max_diff(vector<vector<int>> lol){
  int max = 0;
  for(int i = 0; i < lol.size(); i++){
    if (max < lol[0][i] - lol[1][i]){
      max = lol[0][i] - lol[1][i];
    }
  }
  return max;
}

int find_min_diff(vector<vector<int>> lol){
  int min= 999999999;
  for(int i = 0; i < lol.size(); i++){
    if (min > lol[0][i] - lol[1][i]){
      min = lol[0][i] - lol[1][i];
    }
  }
  return min;
}

int main(){
  int res = 800;
  int vec = 9000;
  vector<vector<int>> values(2,vector<int>(res));
  vector<int> test_vector = create_test(vec);

  for(int i = 0; i < res; i++){
    Node* tree = create_tree(test_vector);
    values[0][i] = max_height(tree);
    values[1][i] = min_height(tree);
    next_permutation(test_vector.begin(),test_vector.end());
    delete tree;
  }

  cout << "Average height: " << average_height(values[0]) << endl;
  cout << "Maximum height: " << find_max_height(values[0]) << endl;
  cout << "Minimum average height: " << average_height(values[1]) << endl;
  cout << "Minimum height: " << find_min_height(values[0]) << endl;
  cout << "Average difference: " << average(values) << endl;
  cout << "Maximum difference: " << find_max_diff(values) << endl;
  cout << "Minimum difference: " << find_min_diff(values) << endl;
  return 0;
}
