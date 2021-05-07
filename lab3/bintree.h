#ifndef BINTREE_H
#define BINTREE_H

struct Node{
  int key;
  double data;
  Node * right;
  Node * left;
};
  
void insert(Node * & p,int key, double to_be_inserted);

void remove(Node *& p, const int & key);
Node * look_left(Node * father, Node * son, const int & to_be_removed);
Node * look_right(Node * father, Node * son, const int& to_be_removed);

const double & find(Node * p, const int & to_be_found);
double & edit(Node * p, const int & to_be_changed);
void delete_tree(Node * & p);

unsigned int max_height(Node * p);
unsigned int min_height(Node * p);
unsigned int size(Node * p);
bool is_balanced(Node * p);

#endif
