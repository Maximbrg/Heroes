/*
 * Hero.h
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */
#include <utility>
#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include "Creature.h"
#include "BlackDragon.h"
#include "Vampire.h"
#include "Wizard.h"
#include "Archer.h"
#include "Zombie.h"
#include "Error.h"
#include <list>
#ifndef HERO_H_
#define HERO_H_

using namespace std;

class Hero {

protected:
	bool _didgetGold;
	bool _didusespeacial;
	string _name;
	string  _type;
	int _gold;
	map<string,pair<Creature*,int> > _army;

public:
//Constracturs
	Hero(const string name);
	//Gettes
	const int getGold()const{return _gold;};
	const string getName()const{return _name;};
	const int getNumOfArmy()const;
	const string getType()const{return _type;};
	//Setters
	void setGold();
	void addCreaturs(const string creatureName, const int number);
	void setdidgold(const int i){if(i==1)_didgetGold=true;else _didgetGold=false;}
	void setdidspecial(const int i){if(i==1)_didusespeacial=true;else _didgetGold=false;}
	//function
	void buyCreaturs(const string creatureName,const int number);
	void addGold(const int number){_gold=_gold+number;if(_gold>2500)_gold=2500;};
	void changeGold(const int number){_gold=number;if(_gold>2500)_gold=2500;};
	void attack(const string myCreature,Hero& h,const string oppnentsCreature);
	void nextTurn(){_didgetGold=false;_didusespeacial=false;};
	void updatearmy(const string creatureName);
	const void print()const;
	//pureVirtual
	virtual void saveData(string path)=0;
	virtual void specalAbility(list<Hero*> players)=0;
	virtual ~Hero();
};

#endif /* HERO_H_ */
