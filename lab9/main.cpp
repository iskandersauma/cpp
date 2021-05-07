#include <iostream>
#include <vector>
#include <string>

using namespace std;

string hard_coded_primes(int N){
  vector<int> listan;
  string s = "{";
  int value;
  int iterator = 1;
  int new_value;
  bool lol = false;
  for(int i = 0; i < N - 1; i++){
    listan.push_back(0);
  }

  for(unsigned int it = 0; it < listan.size(); it++){
    if(listan[it] == 0 && lol == false){
      lol = true;
      value = it+2;
      s+=to_string(value);
      iterator = 1;
      new_value = value;
      while(new_value <= N){
	if(listan[new_value-2] == 0){
	  listan[new_value-2] = 1;
	}
	new_value = value*iterator;
	iterator++;
      }
    }
     if(listan[it] == 0 && lol == true){
      value = it+2;
      s+="," + to_string(value);
      iterator = 1;
      new_value = value;
      while(new_value <= N){
	if(listan[new_value-2] == 0){
	  listan[new_value-2] = 1;
	}
	new_value = value*iterator;
	iterator++;
      }
    }
  }
  s+="}"; 
  cout<<s<<endl;
  return s;
}
int main(){
  int N = 1000;
  string s = hard_coded_primes(N);
  cout<<"vector<int> primes = " + s<<endl;
  
    
  return 0;
}
