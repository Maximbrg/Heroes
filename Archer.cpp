/*
 * Archer.cpp
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */

#include "Archer.h"

Archer::Archer() {
	_attack=5;
	_deff=4;
	_cost=90;
}

void Archer:: Attack(Creature& c){
	double bonusAttack=1;
	if(c.getAtack()==9&&c.getDeff()==10)
		bonusAttack=1.2;
	int totalAttack = (this->_attack*bonusAttack)*this->_counter;
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


Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

