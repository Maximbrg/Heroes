//============================================================================
// Name        : Assigment6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iterator>
#include <list>
#include <vector>
#include <unistd.h>
#include<sys/stat.h>
#include "Hero.h"
#include "Warrior.h"
#include "Thief.h"
#include "Necromancer.h"
#include <algorithm>
using namespace std;

void deleteFIle();
void save(int rounds,int numberPlayers);
bool ifdied(Hero* a);
Hero* special_compare(list<Hero*> players,string name);
void fight(Hero* a, Hero* b);
bool randcomp(Hero* a, Hero* b);
void printOpponents(list<Hero*> players);
list<Hero*> initilizing(int warriors,int theif,int necromancer);
bool randcomp(Hero* a, Hero* b);

int main(int str1, char* args[] ) {
	int currRound;
	int rounds;
	int numberofPlayers;
	list<Hero*> players;
	int a = str1;
	if(a!=2&&a!=5){
		cout<<"not right number of arguments";
		return 1;}

	if(a==2){
		ifstream file_obj;
		string load="";
		file_obj.open("Play/gameInfo.txt");
		getline(file_obj,load);
		currRound = atoi(load.c_str());
		getline(file_obj,load);
		numberofPlayers = atoi(load.c_str());
		rounds=numberofPlayers*3;
		file_obj.close();
		Hero* hero;
		for(int i=1;i<=numberofPlayers;i++){
			string path ="Play/Player";
			char c = i+'0';
			path += c;
			path=path+"/Input.txt";
			file_obj.open(path.c_str());
			load="";
			getline(file_obj,load);
			string name = load;
			getline(file_obj,load);
			if(name.compare("Wrrior")==0)
			{Warrior* a= new Warrior(load);
			 hero=a;}
			if(name.compare("Thief")==0)
			{Thief* b=new Thief(load); hero=b;}
			if(name.compare("Necromancer")==0)
			{Necromancer* c=new Necromancer(load); hero=c;}
			getline(file_obj,load);
			int gold = atoi(load.c_str());
			hero->changeGold(gold);
			int number;
			getline(file_obj,load);
			number=atoi(load.c_str());
			hero->addCreaturs("Black_Dragon",number);
			getline(file_obj,load);
			number=atoi(load.c_str());
			hero->addCreaturs("Wizard",number);
			getline(file_obj,load);
			number=atoi(load.c_str());
			hero->addCreaturs("Archer",number);
			getline(file_obj,load);
			number=atoi(load.c_str());
			hero->addCreaturs("Vampire",number);
			getline(file_obj,load);
			number=atoi(load.c_str());
			hero->addCreaturs("Zombie",number);
			getline(file_obj,load);
			number=atoi(load.c_str());
			hero->setdidspecial(number);
			getline(file_obj,load);
			number=atoi(load.c_str());
			hero->setdidgold(number);
			players.push_back(hero);
			file_obj.close();
		}
		deleteFIle();
	}
	else{
		if(atoi(args[2])>3||atoi(args[2])<0||atoi(args[3])>3||atoi(args[3])<0||atoi(args[4])>3||atoi(args[4])<0){
			cout<<"not right number of argument";
			return 1;
		}
	deleteFIle();
	players =initilizing(atoi(args[2]),atoi(args[3]),atoi(args[4]));
	rounds = (atoi(args[2])+atoi(args[3])+atoi(args[4]))*3;
	currRound = 1 ;
	players.sort(randcomp);
	}
	Archer a2;
	Zombie a1;
	Wizard a4;
	BlackDragon a5;
	Vampire a3;
	int choice=0;
	Hero* curr;

	curr = players.front();
	players.pop_front();
	while(choice!=7){
		cout<<"Welcome "<<(*curr).getName()<<"\n";
		cout<<"What is your next step in the path to victory?\n";
		cout<<"1. Attack\n";
		cout<<"2. Get daily gold\n";
		cout<<"3. Buy creatures\n";
		cout<<"4. Show details\n";
		cout<<"5. Special skill\n";
		cout<<"6. End of my turn\n";
		cout<<"7. Exit\n";
		cin>>choice;
		switch(choice){
		case 1:{
			char attackChoice='9';
			while(attackChoice!='\n'){
				cout<<"1. Show me my opponents\n";
				cout<<"2. Attack hero";
				cin.get();
				attackChoice=cin.get();
				switch(attackChoice){
				case 49:{
					printOpponents(players);
					attackChoice='\n';
					break;
				}
				case 50:{
					if(currRound>rounds){
					string name1;
					cout<<"Please insert your opponent name: ";
					try{
						bool whowin=false;//0- curr, 1- opponent
						cin>>name1;
						Hero* oppnent = special_compare(players,name1);
						int c=1;
						while(c!=3&&c!=4){
							if( ifdied( curr))
								c=3;
							if( ifdied( oppnent))
								c=4;
							switch(c){
							case 1:{
								fight(curr,oppnent);
								c=2;
								break;
							}
							case 2:{
								fight(oppnent,curr);
								c=1;
								break;
							}
							case 4:{
								whowin=false;
								cout<<"‫‪You‬‬ ‫‪have‬‬ ‫‪been‬‬ ‫‪victorious\n‬‬";
								curr->addGold(oppnent->getGold());
								delete oppnent;
								players.remove(oppnent);
								break;
							}
							case 3:{
								cout<<"‫‪‫‪You‬‬ ‫‪have‬‬ ‫‪been‬‬ ‫‪perished‬‬‬‬\n";
								oppnent->addGold(curr->getGold());
								delete curr;
								curr = players.front();
								players.pop_front();
								whowin=true;
								break;
							}

							}
						}

						if(players.size()==0){
							if(!whowin){
								cout << (*curr).getName() << " is the winner !\n";
								delete curr;
								choice=7;
							}
							else{
								cout << name1 << " is the winner !\n";
								delete oppnent;
								choice=7;
							}
						}
						attackChoice='\n';
					}


					catch(Error& e){
						e.Handle();
					}
					attackChoice='\n';
					break;
					}
					else{
					attackChoice='\n';
					cout<<"can't fight until 3 round\n";
					break;
					}
				}

				}
			}
			break;
		}
		case 2:{
			(*curr).setGold();
			break;
		}
		case 3:{
			int op=0;
			int number=0;
			cout<<"1. Buy Zombies.\n";
			cout<<"2. Buy Archers.\n";
			cout<<"3. Buy Vampire.\n";
			cout<<"4. Buy Wizard.\n";
			cout<<"5. Buy Black Dragon.\n";
			cin>>op;

			string names[5] = {"Zombie","Archer","Vampire","Wizard","Black_Dragon"};
			switch(op){
			case 1:{
				a1.print();
				try{
					cin>>number;
					(*curr).buyCreaturs(names[op-1],number);
				}
				catch(Error& e){
					e.Handle();
				}
				break;
			}
			case 2:{
				a2.print();
				try{
					cin>>number;
					(*curr).buyCreaturs(names[op-1],number);
				}
				catch(Error& e){
					e.Handle();
				}
				break;
			}
			case 3:{
				a3.print();
				try{
					cin>>number;
					(*curr).buyCreaturs(names[op-1],number);
				}
				catch(Error& e){
					e.Handle();
				}
				break;
			}
			case 4:{
				a4.print();
				try{
					cin>>number;
					(*curr).buyCreaturs(names[op-1],number);
				}
				catch(Error& e){
					e.Handle();
				}
				break;
			}
			case 5:{
				a5.print();
				try{
					cin>>number;
					(*curr).buyCreaturs(names[op-1],number);
				}
				catch(Error& e){
					e.Handle();
				}
				break;
			}
			default:{
				if(op!= '\n')
					cout<<"wrong key\n";

			}

			break;
			}
			break;
		}
		case 4:{
			try{
				(*curr).print();
			}
			catch(Error& e){
				e.Handle();
			}
			break;
		}
		case 5:{
			try{
				curr->specalAbility(players);
			}
			catch(Error& e){
				e.Handle();
			}
			break;
		}

		case 6:{
			curr->nextTurn();
			players.push_back(curr);
			curr = players.front();
			players.pop_front();
			currRound++;
			break;
		}
		case 7:{

			 mkdir("Play",0777);
			 mkdir("Play/Player1",0777);
			 curr->saveData("Play/Player1");
			 delete curr;
			 int index =2;
			 while(players.size()!=0){
				string path = "Play/Player";
				char c = index+'0';
				path += c;
				 mkdir(path.c_str(),0777);
					curr = players.front();
					curr->saveData(path);
					players.pop_front();
					delete curr;
					index++;

			 }
			 save(currRound,rounds/3);

		}
		}
	}
	return 0;
}

Hero* special_compare(list<Hero*> players,string name)
{
	list<Hero*> :: iterator iter;
	for(iter=players.begin();iter!=players.end();iter++){
		if((*iter)->getName().compare((name))==0)
			return (*iter);
	}
	throw ErrorInvalidHero(name);
}

list<Hero*> initilizing(int warriors,int theif,int necromancer){
	list <Hero*> heros;
	Hero* players[9];
	string name;
	int i;
	int index=0;
	bool isOk=false;

	while(isOk==false){
		try{
			for(i=0;i<warriors;i++){
				cout<<"‫‪Please‬‬ ‫‪insert‬‬ ‫‪warrior‬‬ ‫‪number‬‬ "<<i+1<<" name: ";
				getline(cin,name);
				players[index]= new Warrior(name);
				heros.push_front(players[index]);
				index++;
			}
			isOk=true;
		}
		catch(Error& e){
			e.Handle();
		}

	}
	isOk=false;
	while(isOk==false){
		try{
			for(i=0;i<theif;i++){
				cout<<"‫‪Please‬‬ ‫‪insert‬‬ ‫‪thief‬‬ ‫‪number‬‬ "<<i+1<<" name: ";
				getline(cin,name);
				players[index]= new Thief(name);
				heros.push_front(players[index]);
				index++;
			}
			isOk=true;
		}
		catch(Error& e){
			e.Handle();
		}
	}
	isOk=false;
	while(isOk==false){
		try{
			for(i=0;i<necromancer;i++){
				cout<<"‫‪Please‬‬ ‫‪insert‬‬ ‫‪necromancer‬‬ ‫‪number‬‬ "<<i+1<<" name: ";
				getline(cin,name);
				players[index]= new Necromancer(name);
				heros.push_front(players[index]);
				index++;
			}
			isOk=true;
		}
		catch(Error& e){
			e.Handle();
		}
	}
	return heros;
}

bool randcomp(Hero* a, Hero* b)
{
	return (rand()%2) != 0;
}

bool byTypecomere(Hero* a, Hero* b){
	if(a->getType().compare("Warrior")==0)
		return true;
	else
		if(a->getType().compare("Thief")==0&&b->getType().compare("‫‪Necromancer‬‬")==0)
			return true;
		else{
			if(a->getType().compare("‫‪Necromancer‬‬")==0&&b->getType().compare("‫‪Necromancer‬‬")==0)
				return true;
		}
	return false;
}

void printOpponents(list<Hero*> players){
	players.sort(byTypecomere);
	list<Hero*>:: iterator start;
	for(start=players.begin();start!=players.end();start++)
		cout<<(*start)->getName()<<" "<<(*start)->getType()<<"\n";
}

void fight(Hero* a, Hero* b){
	bool isOk=false;
	while(isOk==false){
		try{
			{
				(*a).print();
				(*b).print();
				cout<<(*a).getName()<<"'s turn ";
				string name1,name2;
				cin>>name1>>name2;
				(*a).attack(name1,(*b),name2);
			}
			isOk=true;
		}
		catch(Error& e){
			e.Handle();
		}
	}
}

bool ifdied(Hero* a){
	if(a->getNumOfArmy()==0)
		return true;
	return false;
}

void save(int rounds,int numberPlayers){
	ofstream file_obj;
		string path1 = "Play/gameInfo.txt";
		file_obj.open(path1.c_str(), ios::app);
		file_obj<<rounds<<"\n"<<numberPlayers;
		file_obj.close();

}


void deleteFIle(){
	remove("Play/Player1/Input.txt");
	remove("Play/Player2/Input.txt");
	remove("Play/Player3/Input.txt");
	remove("Play/Player4/Input.txt");
	remove("Play/Player5/Input.txt");
	remove("Play/Player6/Input.txt");
	remove("Play/Player7/Input.txt");
	remove("Play/Player8/Input.txt");
	remove("Play/Player9/Input.txt");

	remove("Play/Player1");
	remove("Play/Player2");
	remove("Play/Player3");
	remove("Play/Player4");
	remove("Play/Player5");
	remove("Play/Player6");
	remove("Play/Player7");
	remove("Play/Player8");
	remove("Play/Player9");

	remove("Play/gameInfo.txt");
	remove("Play");


}
