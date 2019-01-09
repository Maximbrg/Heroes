/*
 * Wizard.cpp
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */

#include "Wizard.h"

Wizard::Wizard() {
	_attack=8;
	_deff=2;
	_cost=150;
}

void Wizard:: Attack(Creature& c){
	int totalAttack = this->_attack*this->_counter;
	int totalDeff = c.getCount()*c.getDeff();
	totalAttack=totalAttack-c.getDeff();
	while(totalAttack>=0&&c.getCount()!=0){
		c.SetCreature(c.getCount()-1);
		totalDeff=totalDeff-c.getDeff();
		totalAttack=totalAttack-c.getDeff();
	}
}


Wizard::~Wizard() {
	// TODO Auto-generated destructor stub
}

