/*
 * Vampire.cpp
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */

#include "Vampire.h"
#include "Creature.h"

Vampire::Vampire() {
	_attack=4;
	_deff=4;
	_cost=80;
}

void Vampire:: Attack(Creature& c){
	int totalAttack = this->_attack*this->_counter;
	int totalDeff = c.getCount()*c.getDeff();
	//if(totalDeff==0)
	//	throw "Error";
	totalAttack=totalAttack-c.getDeff();
	while(totalAttack>=0&&c.getCount()!=0){
		c.SetCreature(c.getCount()-1);
		totalDeff=totalDeff-c.getDeff();
		totalAttack=totalAttack-c.getDeff();
	}
}


Vampire::~Vampire() {
	// TODO Auto-generated destructor stub
}

