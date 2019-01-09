/*
 * Zombie.cpp
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */

#include "Zombie.h"

Zombie::Zombie() {
	_attack=2;
	_deff=5;
	_cost=50;
}

void Zombie:: Attack(Creature& c){
	int bonusAttack=1;
	if(c.getAtack()==5&&c.getDeff()==4)
		bonusAttack=2;
	int totalAttack = (this->_attack*bonusAttack)*this->_counter;
	 int totalDeff = c.getCount()*c.getDeff();
	totalAttack=totalAttack-c.getDeff();
	while(totalAttack>=0&&c.getCount()!=0){
		c.SetCreature(c.getCount()-1);
		totalDeff=totalDeff-c.getDeff();
		totalAttack=totalAttack-c.getDeff();
	}
}

Zombie::~Zombie() {
	// TODO Auto-generated destructor stub
}

