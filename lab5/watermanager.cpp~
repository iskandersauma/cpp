#include <iostream>
#include <unordered_map>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "watermanager.h"
#include <random>

WaterManager waterhole1;
unordered_map<thread::id,string> trace;

class Gnu{
public:
  int id;
  Gnu(int id) : id(id){};
  void operator()(){
    int drink = (rand()%3)+1;
    int sleep = (rand()%4)+3;
    this_thread::sleep_for(chrono::seconds(sleep));
    cout<<trace[this_thread::get_id()]<<" is thirsty"<<endl;
    waterhole1.gnuEnters();
    this_thread::sleep_for(chrono::seconds(drink));
    waterhole1.gnuLeaves();
  };
};

ostream& operator<<(ostream& os, const Gnu& g){
  os <<"Gnu nr " <<g.id<<endl;
}

void WaterManager::gnuEnters(){
  unique_lock<mutex> somelock(m);
  cond.wait(somelock,[this]{return hyenasInside == 0;});
  gnusInside += 1;
  cout << trace[this_thread::get_id()]<<" enters the waterhole." << " nr gnu: " << gnusInside << ", nr hyenas: " << hyenasInside<<endl;
}

void WaterManager::gnuLeaves(){
  m.lock();
  gnusInside -=1;
  cout << trace[this_thread::get_id()]<<" leaves the waterhole." << " nr gnu: "<< gnusInside<<", nr hyenas: "<<hyenasInside <<endl;
  cond.notify_all();
  m.unlock();
}

void WaterManager::hyenaEnters(){
  unique_lock<mutex> somelock(m);
  cond.wait(somelock,[this]{return gnusInside == 0;});
  hyenasInside += 1;
  cout<<trace[this_thread::get_id()]<<" enters the waterhole." << " nr gnu: " << gnusInside << ", nr hyenas: " << hyenasInside<<endl;
}

void WaterManager::hyenaLeaves(){
  m.lock();
  hyenasInside -= 1;
  cout<<trace[this_thread::get_id()]<<" leaves the waterhole." << " nr gnu: "<< gnusInside<<", nr hyenas: "<<hyenasInside <<endl;
  cond.notify_all();
  m.unlock();
}

void hyenas(){
  int drink = (rand()%3)+1;
  int sleep = (rand()%4)+3;
  this_thread::sleep_for(chrono::seconds(sleep));
  cout<<trace[this_thread::get_id()]<<" is thirsty"<<endl;
  waterhole1.hyenaEnters();
  this_thread::sleep_for(chrono::seconds(drink));
  waterhole1.hyenaLeaves();
}

int main(){
  int nrGnus = 3;
  int nrHyenas = 3;
  vector<thread> threadvec;
  for (int i = 0; i < nrGnus; i++){
    Gnu g = Gnu(i);
    function<void(void)> threadjob = g;
    threadvec.push_back(thread(threadjob));
    trace[threadvec.back().get_id()]  = "Gnu nr "+to_string(i+1);
  }
  for (int i = 0; i < nrHyenas; i++){
    threadvec.push_back(thread(hyenas));
    trace[threadvec.back().get_id()]  = "Hyena nr "+to_string(i+1);
  }
  for (int i = 0; i < nrGnus+nrHyenas; i++)
    threadvec[i].join();
}

 
