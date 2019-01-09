/*
 * Necromancer.cpp
 *
 *  Created on: 4 Jan 2019
 *      Author: max
 */
#include <list>
#include "Necromancer.h"
#include "Creature.h"
#include <fstream>
#include <iostream>

Necromancer::Necromancer(string name): Hero(name) {
	_type="Necromancer";

}
void Necromancer:: specalAbility(list<Hero*> players){
	if(_didusespeacial==false){
	map<string,pair<Creature*,int> >:: iterator c;
	c = _army.find("Zombie");
	(*c).second.first->SetCreature(c->second.first->getCount()+1);
	(*c).second.second=c->second.first->getCount();
	cout<<"Zombie added successfully\n";
	_didusespeacial=true;
	}
}
void Necromancer::saveData(string path){
	ofstream file_obj;
	string path1 = path+"/Input.txt";
	file_obj.open(path1.c_str(), ios::app);
	file_obj<<"Necromancer"<<"\n"<<this->getName()<<"\n"<<this->getGold()<<"\n";
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
Necromancer::~Necromancer() {
	// TODO Auto-generated destructor stub
}

