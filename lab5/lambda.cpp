#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct A {
    int data;

};

void foo(unique_ptr<A> p) {
    cout << p->data << endl;
}

void foo2(shared_ptr<A> p) {
    cout << p->data << endl;
}

struct BhasA;

struct AhasB {
    AhasB(shared_ptr<BhasA> b) : m_b(b)  {
        resource = new int[4];
    };

    weak_ptr<BhasA> m_b;
    int * resource;

    ~AhasB() {delete [] resource;}
    AhasB(const AhasB &) = delete;
    void operator=(const AhasB &) = delete;
};

struct BhasA {
    BhasA() {resource = new int[4];};

    shared_ptr<AhasB> m_a;
    int * resource;

    ~BhasA() {delete [] resource;}
    BhasA(const BhasA &) = delete;
    void operator=(const BhasA &) = delete;
};

struct B {
    B() { b = new int[4]; }

    int * b;
    ~B() { delete [] b; }
    B(const B &) = delete;
    void operator= (const B & ) = delete;
};

int main(){
  vector<int> v = {1,3,4,5,6,7,8,9};
  int outsidedata = 5;
  //auto odd_numbers = [](int a){if(a % 2 == 1) cout<<a<<endl;};
  //auto multiply = [](int& a){if(a % 2 == 1) a=a*2;};
  auto add = [v](int & a){a = a + v.size();};
  auto change = [& outsidedata](int& a,int b){a= b;}; 
  for_each(v.begin(),v.end(),add);
  change(outsidedata,10);
  cout<<outsidedata<<endl;

  unique_ptr<A> pa(new A {4});
  cout<<pa->data<<endl;
  foo(move(pa));
  
  shared_ptr<A> sa(new A {5});
  cout<<sa-> data<<endl;
  foo2(sa);
  //foo2(move(sa));

  weak_ptr<A> wa = sa;
  cout<<wa.lock()->data<<endl;
	   
  shared_ptr<BhasA> bptr(new BhasA);
  shared_ptr<AhasB> aptr(new AhasB(bptr));
  bptr->m_a=aptr;

  auto deleter = [&](B* b){delete [] b;};
  unique_ptr<B, decltype(deleter)> pb2(new B[2], deleter);
  function<void(B*)> fb = [&](B* b){delete [] b;};
  unique_ptr<B, function<void(B*)>> pb(new B[2],[&](B* b){delete[] b;});
}
