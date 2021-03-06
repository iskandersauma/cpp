#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

class Princess{
public:
  string location = "courtyard";
};

class Player{
public:
  string location = "clearing";
  string weapon = "None";
  string item = "None";
  bool winner = false;
};

class Ogre{
public:
  string weapon = "club";
  string item = "None";
  string location = "gate";
  string status = "Alive";
};

class Club{
public:
  string owner = "ogre";
  string location = "gate";
};

class Choco{
public:
  string owner = "None";
  string location = "clearing";
};

Player* player = new Player();
Ogre* ogre = new Ogre();
Club* club = new Club();
Choco* chocolate = new Choco();
Princess* princess = new Princess();


vector<string> split(string s, char delimiter){
  vector<string> result;
  istringstream iss(s);
  for(string s; iss >> s; ){
    result.push_back(s);
  }
  return result;
}

void look(){
  if(player->location == "clearing"){
    cout<<"You are in a clearing. ";
    if(chocolate->owner == "None"){
      cout<<"On the ground there is a box of chocolate";
    }
    cout<<"\n"<<endl;
    cout<<"Looking around you see."<<endl;
    cout<<"North - Villagers cheering for your success!"<<endl;
    cout<<"West - Cannibals"<<endl;
    cout<<"East - Pack of hyenas starring at you suggestively..."<<endl;
    cout<<"South - Gate to a castle"<<endl;
    cout<<"You should probably go south."<<endl;
  }
  else if(player->location == "gate"){
    cout<<"You are in front of a castle gate. ";
    if(ogre->status == "Dead"){
      cout<<"In front of you lies a dead ogre."<<endl;
    }
    else if(ogre->location == "gate" && ogre->item == "None"){
      cout<<"In front of the gate, there is a hungry ogre armed with a club."<<endl;
    }
    else if(ogre->location == "gate" && ogre->item == "chocolate"){
      cout<<"The gate is unguarded."<<endl;
    }
    cout<<"Looking around you see."<<endl;
    cout<<"North - clearing"<<endl;
    cout<<"West - Danish people"<<endl;
    cout<<"East - A bunch of millenials complaining"<<endl;
    cout<<"South - A courtyard"<<endl;
    cout<<"You should probably go south here"<<endl;
  }
  else if(player->location == "courtyard"){
    cout<<"You are inside the castle and the princess is standing in front of you."<<endl;
    cout<<"Looking around you see."<<endl;
    cout<<"North - Exit"<<endl;
    cout<<"West - Wall"<<endl;
    cout<<"East - Wall"<<endl;
    cout<<"South - Wall"<<endl;
    cout<<"You can only travel north."<<endl;
  }
}

void take(string command){
  if(command == "chocolate" || command == "Chocolate"){
    if(chocolate->location == player->location && chocolate->owner == "None"){
      player->item = "chocolate";
      chocolate->owner = "player";
      chocolate->location = "clearing";
      cout<<"You picked up chocolate"<<endl;
    }
    else if(chocolate->location != player->location){
      cout<<"How long do you think your arms are???"<<endl;
    }
    else{
      cout<<"Stealing is wrong...m'kay!!"<<endl;
    }
  }
  else if(command  == "club" || command == "Club"){
    if(club->location == player->location && club->owner == "None"){
      player->weapon = "club";
      cout<<"You now have a weapon."<<endl;
    }
    else if(club->location != player->location){
      cout<<"How long do you think your arms are???"<<endl;
    }
    else if(club->owner == "ogre"){
      cout<<"Ogre sees you stealing and screams at you. You get scared and start crying."<<endl;
    }
  }
  else if(command == "Princess" || command == "princess" || command == "pippi" || command == "Pippi"){
    cout<<"Princess Pippi resists your kidnapping attempt."<<endl;
  }
  else{
    cout<<"take what?"<<endl;
  }
}

void go(string command){
  if(player->location == "clearing"){
    if(command == "South" || command == "s" || command == "S" || command == "south"){
      player->location = "gate";
      cout<<"You are now in front of the gate."<<endl;
    }
    else if(command  == "north" || command == "n" || command == "North" || command == "N"){
      cout<<"The villagers look at eachother confused. They eventually send you back thinking you're retarded."<<endl;
    }
    else if(command == "west" || command == "West" || command == "w" || command == "W"){
      cout<<"You approach the cannibals and immediately realize your misstake but too late..."<<endl;
      cout<<"You lose...badly!"<<endl;
      player->winner = true;
    }
    else if(command == "east" || command == "East" || command == "e" || command == "E"){
      cout<<"You try to around the hyenas but they follow you and eventually you meat your fate...(notice the pun :) )"<<endl;
      cout<<"You lose!"<<endl;
      player->winner = true;
    }
    else{
      cout<<"Just go south"<<endl;
    }
  }
  else if(player->location == "gate"){
    if(command  == "south" || command == "s" || command == "South" || command == "S"){
      if(ogre->item == "chocolate"){
	player->location = "courtyard";
	cout<<"you are now in the courtyard"<<endl;
      }
      else{
	cout<<"Ogre is blocking the way!"<<endl;
      }
    }
    else if(command  == "north" || command == "n" || command == "North" || command == "N"){
      player->location = "clearing";
      cout<<"You are now in a clearing"<<endl;
    }
    else if(command == "west" || command == "West" || command == "w" || command == "W"){
      cout<<"You try talking to the danes but you can't understand them...who can? So you go back."<<endl;
    }
    else if(command == "east" || command == "East" || command == "e" || command == "E"){
      cout<<"You get close to the millenials and start wondering why you went there. You turn back."<<endl;
    }
    else{
      cout<<"Shouldn't you rescue the princess?"<<endl;
    }
  }
  else if(player->location == "courtyard"){
    if(command  == "south" || command == "s" || command == "South" || command == "S"){
      cout<<"You run into a wall. It hurt."<<endl;
    }
    else if(command  == "north" || command == "n" || command == "North" || command == "N"){
      player->location = "gate";
      cout<<"You are not outside the gate"<<endl;
    }
    else if(command == "west" || command == "West" || command == "w" || command == "W"){
     cout<<"You run into a wall. It hurt."<<endl;
    }
    else if(command == "east" || command == "East" || command == "e" || command == "E"){
      cout<<"You run into a wall. It hurt."<<endl;
    }
    else{
      cout<<"Shouldn't you rescue the princess?"<<endl;
    }
  }

  if(player->weapon == "club"){
    club->location = player->location;
  }

  if(player->item == "chocolate"){
    chocolate->location = player->location;
  }
}

void give(string command){
  if(command == "Princess" || command == "princess" || command == "pippi" || command == "Pippi"){
    cout<<"You are one sick puppy."<<endl;
  }
  else if(player->item == "None" && player->weapon == "None"){
    cout<<"Give what exactly??"<<endl;
  }
  else if(ogre->status == "Dead"){
    cout<<"Can't give things to dead ogres..."<<endl;
  }
  else if(player->weapon == command && player->location == ogre->location){
    cout<<"Dont give away your weapon..."<<endl;
  }
  else if(player->item == command && player->location == ogre->location){
    cout<<"Ogre takes the chocolate and gives you his club and starts eating beside the gate."<<endl;
    player->item = "None";
    player->weapon = "club";
    ogre->item = "chocolate";
    ogre->weapon = "None";
    club->owner = "player";
  }
  else{
    cout<<"give what??"<<endl;
  }
}

void talk(string command){
  if((command == "Princess" ||command == "princess") && player->location == princess->location){
    cout<<"-Stop talking and get me out of here!!"<<endl;
  }
  else if((command == "ogre" || command == "Ogre") && ogre->status == "Dead"){
    cout<<"Dead ogres can't talk can they??"<<endl;
  }
  else if((command == "ogre" || command == "Ogre") && player->location == ogre->location){
    cout<<"- Are you hangry if you are angry because you're hungry or hungry because you're angry??"<<endl;
  }
  else{
    cout<<"You get no answer..."<<endl;
  }
}

void rescue(string command){
  if((command == "Princess" || command == "princess" || command == "pippi" || command == "Pippi") && player->location == princess->location){
    cout<<"You have saved the princess!!!"<<endl;
    cout<<"You have won!"<<endl;
    player->winner = true;
  }
  else{
    cout<<"But where is princess Pippi?"<<endl;
  }
}

void attack(string command){
  if(player->weapon == "None"){
    cout<<"you got no weapons for that"<<endl;
  }
  else if((command == "Princess" || command == "princess" || command == "pippi" || command == "Pippi") && player->location == princess->location){
    cout<<"The princess is killed. How will you ever be able to return home now?"<<endl;
    player->winner = true;
    cout<<"You lose!..."<<endl;
  }
  else if((command == "ogre" || command == "Ogre") && player->location == ogre->location){
    cout<<"The ogre is slain despite posing no threat!"<<endl;
    ogre->status = "Dead";
  }
  else{
    cout<<"can't do that"<<endl;
  }
}

void dab(){
  cout<<"You do a dab and feel embarrassed."<<endl;
}

void tips(){
  cout<<"The ogre is hangry. Maybe feeding him will help??"<<endl;
}
void tutorial(){
  cout<<"Tutorial -"<<endl;
  cout<<"look - if you want to look around"<<endl;
  cout<<"Take ... - if you want to take an object"<<endl;
  cout<<"go ... - to change location"<<endl;
  cout<<"talk ... - to open dialog"<<endl;
  cout<<"give ... - to give an object to ogre"<<endl;
  cout<<"attack ... - to attack another character"<<endl;
  cout<<"rescue ... - save character"<<endl;
}

int main(){
  unordered_map<string, function<void(void)>> table1;
  unordered_map<string, function<void(string)>> table2;
  
  table1["look"]  = look;
  table1["Look"] = look;
  table1["dab"] = dab;
  table1["dabb"] = dab;
  table1["Dab"] = dab;
  table1["tutorial"] = tutorial;
  table1["Tutorial"] = tutorial;
  table1["tips"] = tips;
  table1["Tips"] = tips;

  table2["take"] = take;
  table2["Take"] = take;
  table2["go"] = go;
  table2["Go"] = go;
  table2["rescue"] = rescue;
  table2["Rescue"] = rescue;
  table2["rescure"] = rescue;
  table2["talk"] = talk;
  table2["Talk"] = talk;
  table2["give"] = give;
  table2["Give"] = give;
  table2["attack"] = attack;
  table2["Attack"] = attack;

  cout<<"You have been tasked to save Princess Pippi who is being help captive in the castle, but being a poor peasant you got no weapons."<<endl;
  cout<<"Can you save the princess?"<<endl;

  cout<<"Tutorial -"<<endl;
  cout<<"look - if you want to look around"<<endl;
  cout<<"Take ... - if you want to take an object"<<endl;
  cout<<"go ... - to change location"<<endl;
  cout<<"talk ... - to open dialog"<<endl;
  cout<<"give ... - to give an object to ogre"<<endl;
  cout<<"attack ... - to attack another character"<<endl;
  cout<<"rescue ... - save character"<<endl;
  cout<<"tips - in case you feel lost"<<endl;
  cout<<"Use tutorial to read these whenever"<<endl;
  cout<<"Other command may exist ... :)"<<endl;
  while(player->winner != true){
    string s;
    getline(cin,s);
    cout<<"\n";
    vector<string> vec = split(s,' ');
    if(vec.size() == 1){
      if (table1.find(vec[0]) == table1.end()){
        cout <<"You can't do that"<<endl;
      }
      else{ 
	table1[vec[0]]();
      }
    }
    else if(vec.size() == 2){
      if(table2.find(vec[0]) == table2.end()){
	cout<<"You can't do that"<<endl;
      }
      else{
	table2[vec[0]](vec[1]);
      }
    }
    else{
      cout<<"Read the tutoraial again please!"<<endl;
    }
  }
  return 0;
}
