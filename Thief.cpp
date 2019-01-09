/*
 * Thief.cpp
 *
 *  Created on: 4 Jan 2019
 *      Author: max
 */

#include "Thief.h"
#include<list>
#include <fstream>
#include <iostream>

Thief::Thief(string name): Hero(name){
	_type="Thief";

}

void Thief:: specalAbility(list<Hero*> players){
	if(_didusespeacial==false){
	string name;
	cout<<"‫‪Please‬‬ ‫‪insert‬‬ ‫‪hero‬‬ ‫‪name:\n‬‬";
	cin>>name;
	try{
		Hero* oppnent = special_compare(players,name);
			if(oppnent->getGold()<70)
				this->addGold(oppnent->getGold());
			else{
				oppnent->addGold(-70);
				this->addGold(70);

			}
			_didusespeacial=true;
	}
	catch(Error& e){
		e.Handle();
	}

	}
}
void Thief::saveData(string path){
	ofstream file_obj;
	string path1 = path+"/Input.txt";
	file_obj.open(path1.c_str(), ios::app);
	//file_obj.write((char*)&obj, sizeof(obj));
	file_obj<<"Thief"<<"\n"<<this->getName()<<"\n"<<this->getGold()<<"\n";
	int num=0;
	map<string,pair<Creature*,int> >:: iterator iter;
		string names[5] = {"Black_Dragon","Wizard","Archer","Vampire","Zombie"};
		for(int i=0;i<5;i++){
			iter = _army.find(names[i]);
			num=iter->second.second;
			file_obj<<num<<"\n";
		}
		file_obj<<this->_didusespeacial<<"\n"<<this->_didgetGold;
	file_obj.close();
}

Thief::~Thief() {
	// TODO Auto-generated destructor stub
}

 Hero* Thief:: special_compare(list<Hero*> players,string name)
{
		list<Hero*> :: iterator iter;
		for(iter=players.begin();iter!=players.end();iter++){
			if((*iter)->getName().compare((name))==0)
				return (*iter);
		}
		throw ErrorInvalidHero(name);
}
