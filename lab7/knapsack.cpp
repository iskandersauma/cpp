#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <sstream>
#include <vector>

using namespace std;
map<int, int> mapvalues = {
  {16, 24},
  {19, 29},
  {15, 23},
  {14, 22},
  {13, 21},
  {17, 28},
};
 

void printmap(){
  cout<< "weight , values" <<endl;
  for(auto i = mapvalues.rbegin(); i != mapvalues.rend(); ++i){
    cout<< i->first <<" , "<<i->second<<endl;
  }
  cout <<endl;
}
 
template <typename S>
string greedytake(S start, S end, int N) {
   stringstream ss;
   stringstream ws;
   stringstream vs;
   int weight = 0;
   int value  = 0;
   bool firstTime = false;
   int iterator;
   ss << "knapsacksize = " << N << " got value ";

   for(auto i = start; i != end; i++){
     iterator = 0;
     while(weight + i-> first <= N){
       iterator++;
       weight += i->first;
       value += i->second;
     }
     if(firstTime == true && iterator != 0){
       vs<<" + "<< iterator<<"*"<<i->second;
       ws<<" + "<< iterator<<"*"<<i->first;
     }
     else if(firstTime == false && iterator != 0){
       vs<<iterator<<"*"<<i->second;
       ws<<iterator<<"*"<<i->first;
       firstTime = true;
     }
   }
   ss << value <<" = "<< vs.str()<<" used weight "<<weight<<"/"<<N <<" = "<<ws.str()<< endl;
   return ss.str();
}

template <class T>
vector< pair<int, int> > dynamictake(T begin, T end,int N){
  vector< pair<int, int> > res;
  int weight = 0;
  int value = 0;
  int totalweight = 0;
  int totalvalue = 0;
  for(int size = 0; size <= N; size++){
     weight = 0;
     value = 0;
    for(auto i = begin; i != end; i++){
      totalweight = size - i->first;
      if(totalweight < 0){
	totalweight = size;
	totalvalue = 0;
      }
      else{
	totalvalue = res.at(totalweight).second + i->second;
	totalweight = size;
      }
      if(totalvalue > value){
	weight = totalweight;
	value = totalvalue;
      }
    }
    res.push_back({weight,value});
  }
  return res;
}


int main() {
  int N = 50;   
  printmap();

  cout<<greedytake(mapvalues.rbegin(),mapvalues.rend(),N)<<endl;
  
  function<bool(pair<int, int>, pair<int, int>)> 
    densitycompare = [](pair<int,int> a,pair<int,int> b){
    if((a.first/a.second) < (b.first/b.second)){
      return true;
    }
    else{
      return false;
    }
  };
  
  set<pair<int, int>, function<bool(pair<int, int>, pair<int, int>)> > 
  valuedensities(mapvalues.begin(), mapvalues.end(), densitycompare);
  
  cout<<greedytake(valuedensities.rbegin(),valuedensities.rend(),N)<<endl;
  
  
  
  vector< pair<int, int> > resultat;
  resultat = dynamictake(mapvalues.rbegin(),mapvalues.rend(),N);
  for(unsigned int i = 0; i < resultat.size(); i++){
    cout<<"knapsacksize: "<<i<<" , accumulated value: "<<resultat[i].second<<endl;
    }
  return 0;
}

