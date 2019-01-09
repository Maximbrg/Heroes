/*
 * Warrior.cpp
 *
 *  Created on: 4 Jan 2019
 *      Author: max
 */

#include "Warrior.h"

Warrior::Warrior(string name): Hero(name)
{
	_type="Warrior";
}
void Warrior::specalAbility(list<Hero*> players){
	if(_didusespeacial==false){
	_gold=_gold+50;
	if(_gold>2500) _gold=2500;
	cout<<"Gold added successfully\n";
	_didusespeacial=true;
	}
}
void Warrior::saveData(string path){
	ofstream file_obj;
	string path1 = path+"/Input.txt";
	file_obj.open(path1.c_str(), ios::app);
	//file_obj.write((char*)&obj, sizeof(obj));
	file_obj<<"Wrrior"<<"\n"<<this->getName()<<"\n"<<this->getGold()<<"\n";
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
Warrior::~Warrior() {
	// TODO Auto-generated destructor stub
}

