/*
 * Hero.cpp
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */

#include "Hero.h"
#include <utility>


Hero::Hero(const string name) {

	if(name.size()>31)
		throw ErrorInvalidName();
	unsigned int i;
	for(i=0;i<name.size();i++){
		char c=name[i];
		if(c==32){
			throw ErrorInvalidName();
			break;
		}
		if((c>47&&c<58)||(c>64&&c<91)||(c>96&&c<123))
			continue;
		else{
			throw ErrorInvalidName();
			break;
		}
	}

	_didgetGold=false;
	_didusespeacial=false;
	_name=name;
	_gold=750;
	_type="";
	Zombie* z = new Zombie();
	Vampire* v = new Vampire();
	Wizard* w = new Wizard();
	Archer* a = new Archer();
	BlackDragon* b = new BlackDragon();

	pair<Creature*,int>p1,p2,p3,p4,p5;
	p1.first=z;
	p1.second=0;
	p2.first=v;
	p2.second=0;
	p3.first=w;
	p3.second=0;
	p4.first=a;
	p4.second=0;
	p5.first=b;
	p5.second=0;

	_army.insert(pair<string,pair<Creature*,int> >("Zombie",p1));
	_army.insert(pair<string,pair<Creature*,int> >("Vampire",p2));
	_army.insert(pair<string,pair<Creature*,int> >("Wizard",p3));
	_army.insert(pair<string,pair<Creature*,int> >("Archer",p4));
	_army.insert(pair<string,pair<Creature*,int> >("Black_Dragon",p5));


}

const void Hero::print()const{
	cout<<_name<<" "<<_type<<":\n";
	cout<<_gold<<" gold\n";
	map<string,pair<Creature*,int> >:: const_iterator iter;
	string names[5] = {"Black_Dragon","Wizard","Archer","Vampire","Zombie"};
	for(int i=0;i<5;i++){
		iter = _army.find(names[i]);
		if((*iter).second.second!=0)
			cout << iter->second.second << " " << iter->first<<" ";
	}
	cout<<"\n";
}

void Hero:: buyCreaturs(const string creatureName,const int number){
	map<string,pair<Creature*,int> >:: iterator c;
	c = _army.find(creatureName);
	int totalCost = (*c).second.first->getCost()*number;
	if(totalCost>_gold)
		throw ErrorNotEnoughMoney();
	else{
		_gold=_gold-totalCost;
		(*c).second.first->SetCreature(c->second.first->getCount()+number);
		(*c).second.second=c->second.first->getCount();
	}

}

void Hero::attack(const string myCreature,Hero& h,const string oppnentsCreature){

	string names[5] = {"Black_Dragon","Wizard","Archer","Vampire","Zombie"};

	bool isOk=false;
	for(int i=0; i<5 && isOk==false;i++){
		if(names[i]==myCreature)
			isOk=true;
	}
	if(isOk==false)
		throw ErrorNoSuchCreature(myCreature);
	isOk=false;
	for(int i=0; i<5 && isOk==false;i++){
		if(names[i]==oppnentsCreature)
			isOk=true;
	}
	if(isOk==false)
		throw ErrorNoSuchCreature(oppnentsCreature);
	map<string,pair<Creature*,int> >:: iterator my;
	my = _army.find(myCreature);
	if(my->second.second!=0){
		map<string,pair<Creature*,int> >:: iterator his;
		his = h._army.find(oppnentsCreature);

		if(his->second.second!=0){
			my->second.first->Attack(*his->second.first);
			h.updatearmy(oppnentsCreature);
		}
		else
			throw ErrorNoSuchCreatureArmy(oppnentsCreature);
	}
	else
		throw ErrorNoSuchCreatureArmy(myCreature);
}

void Hero:: setGold(){
	if(_didgetGold==false){
		_gold=_gold+100;
		_didgetGold=true;
		if(_gold>2500)
			_gold=2500;
	}
}

Hero::~Hero() {
	map<string,pair<Creature*,int> >:: iterator iter;
	string names[5] = {"Black_Dragon","Wizard","Archer","Vampire","Zombie"};
	for(int i=0;i<5;i++){
		iter = _army.find(names[i]);
		delete iter->second.first;
	}
}

const int Hero:: getNumOfArmy()const{
	int num=0;
	map<string,pair<Creature*,int> >:: const_iterator const_iter;
	string names[5] = {"Black_Dragon","Wizard","Archer","Vampire","Zombie"};
	for(int i=0;i<5;i++){
		const_iter = _army.find(names[i]);
		num=const_iter->second.second+num;
	}
	return num;
}

void Hero::updatearmy(const string creatureName){
	map<string,pair<Creature*,int> >:: iterator c;
	c = _army.find(creatureName);
	c->second.second = c->second.first->getCount();
}


void Hero::addCreaturs(const string creatureName, const int number){
	if(number!=0){
	map<string,pair<Creature*,int> >:: iterator c;
	c = _army.find(creatureName);
	(*c).second.first->SetCreature(c->second.first->getCount()+number);
	(*c).second.second=c->second.first->getCount();
	}
}




