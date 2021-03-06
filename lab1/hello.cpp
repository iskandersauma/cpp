#include <iostream>

#include "hello.h"

void hello(const char * name, int count){
  if(count == -2){
    std::cout<<"Hello, world!"<<std::endl;
  }
  else if(count == 0){
    std::cout<<"Hello, "<<name<<"!"<<std::endl;
  }
  else if(count >0){
    std::cout<<"Hello,";
    for (int i = 0; i < count;i++){
      std::cout<<" "<<name;
    }
    std::cout<<"!"<<std::endl;
  }
}

std::pair<const char *,int> parse_args (int argc, char * argv[]){
  int count =1;

  if (argc ==1){
    count = -2;
    return std::make_pair(argv[1],count);
  }
  if(argc == 2){
    count =0;
    return std::make_pair(argv[1],count);
  }
  if(argc >3){
    std::cerr<<"error: Too many arguments!"<<std::endl;
    count = -3;
    return std::make_pair(argv[1],count);
  }
  try{std::stoi(argv[2]);}
  catch(...){
    std::cerr<<"2nd argument must be an integral"<<std::endl;
    return std::make_pair(argv[1],-3);
  }

  if(std::stoi(argv[2]) == 0){
    count= -3;
    return std::make_pair(argv[1],count);
  }
  else if(std::stoi(argv[2]) < 0){
    std::cerr<<"error: 2nd argument must be an integral greater than zero!"<<std::endl;
    count = -3;
    return std::make_pair(argv[1],count);
  }
  else if(argc ==3){
    count =std::stoi(argv[2]);
    return std::make_pair(argv[1],count);
  }
  return std::make_pair(argv[1],count);
}
