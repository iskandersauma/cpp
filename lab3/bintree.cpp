#include "bintree.h"
#include <iostream>
#include <algorithm>

using namespace std;

void insert(Node * & p,int key, double to_be_inserted){
  if(p == nullptr){
    p = new Node();
    p->key = key;
    p->data  =to_be_inserted;
    p->left = nullptr;
    p->right = nullptr;
  }
  else if(p->key < key){
    insert(p->right,key,to_be_inserted);
  }
  else if(p->key > key){
    insert(p->left,key,to_be_inserted);
  }
  else{
    p->data = to_be_inserted;
  }
}

const double & find(Node * p, const int & to_be_found){
  if(p->key == to_be_found && p != nullptr){
    return p->data;
  }
  else if(p->key < to_be_found && p->right != nullptr){
    find(p->right, to_be_found);
  }
  else if(p->key > to_be_found && p->left != nullptr){
    find(p->left,to_be_found);
  }
  else{
    cerr<<"does not exist"<<endl;
  }
}

double & edit(Node * p, const int & to_be_changed){
  if(p->key == to_be_changed && p!= nullptr){
    return p->data;
  }
  else if(p->key < to_be_changed && p->right != nullptr){
    edit(p->right, to_be_changed);
  }
  else if(p->key > to_be_changed && p->left != nullptr){
    find(p->left,to_be_changed);
  }
  else{
    cerr<<"does not exist"<<endl;
  }
}

unsigned int max_height(Node * p){
  if(p != nullptr){
    unsigned int lmax = max_height(p->left);
    unsigned int hmax = max_height(p->right);
    return max(lmax,hmax) + 1;
  }
  else{
    return 0;
  }
}

unsigned int min_height(Node * p){
  if(p == nullptr){
    return 0;
  }
  else{
    unsigned int lmin = min_height(p->left);
    unsigned int hmin = min_height(p->right);
    return min(lmin,hmin)+1;
  }
}

bool is_balanced(Node * p){
  unsigned int maximum = max_height(p);
  unsigned int minimum = min_height(p);
  if((maximum - minimum) <= 1){
    return true;
  }
  else{
    return false;
  }
}

unsigned int size(Node * p){
  if(p != nullptr){
    unsigned int size_left = size(p->left);
    unsigned int size_right = size(p->right);
    return size_left + size_right + 1;
  }
  else{
    return 0;
  }
}

void delete_tree(Node * & p){
  if(p != nullptr){
    delete_tree(p->left);
    delete_tree(p->right);
    delete p;
  }
}

void remove(Node *& p, const int & key){
  if (p==nullptr){
    cout<<"Does not exist"<<endl;
  }
  else if(p->key == key){
    if(p->left == nullptr && p->right == nullptr){
      delete p;
      p = nullptr;
    }
    else{
      Node * replacement = ((max_height(p->left)>max_height(p->right)) ? look_left(p,p->left,key): look_right(p,p->right,key));
      p->key = replacement->key;
      p->data = replacement->data;
      delete_tree(replacement);
    }
  }
  else{
    Node* son = ((p->key >key) ? p->left : p->right);
    remove(son,key);
  }
}

Node * look_left(Node * father, Node * son, const int & to_be_removed){
  if(son->right == nullptr){
    Node* ny = new Node;
    ny = son;
    if(father->key == to_be_removed){
      father->right = ny->right;
    }
    else{
      father->left = ny->right;
    }
    return ny;
  }
  return look_left(son,son->right,to_be_removed);
}

Node * look_right(Node * father, Node * son, const int& to_be_removed){
  if(son->left == nullptr){
    Node* ny = new Node;
    ny = son;
    if(father->key == to_be_removed){
      father ->right = ny->right;
    }
    else{
      father->left = ny->right;
    }
    return ny;
  }
  return look_right(son,son->left,to_be_removed);
}
/* 
int main(){

  Node * p = nullptr;
  
  insert(p,3,3.1);
  insert(p,2,0.5);
  insert(p, 1 , 0.2);
  insert(p, 5 , 5.5);
  cout<<find(p,2)<<endl;
  
  cout<<max_height(p)<<endl;
  cout<<min_height(p)<<endl;

  cout<<is_balanced(p)<<endl;

  cout<<size(p)<<endl;
  edit(p,3) = 0.001;
  cout<<find(p,3)<<endl;

  
  Node * q = nullptr;
  insert(q,1,2.5);
  remove(q,1);
  cout<<size(q)<<endl;

  delete_tree(q);
  remove(p,3);
  cout<<size(p)<<endl;
  delete_tree(p);
};

*/
