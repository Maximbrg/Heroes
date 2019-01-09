/*
 * BlackDragon.cpp
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */

#include "BlackDragon.h"

BlackDragon::BlackDragon() {
	_attack=9;
	_deff=10;
	_cost=200;
}

void BlackDragon:: Attack(Creature& c){
	int bonusDeff=1;
	int totalAttack = this->_attack*this->_counter;
	if(c.getAtack()==8&&c.getDeff()==2)
		bonusDeff=2;
	 int totalDeff = c.getCount()*(c.getDeff()*bonusDeff);
	//if(totalDeff==0)
	//	throw "Error";
	totalAttack=totalAttack-(c.getDeff()*bonusDeff);
	while(totalAttack>=0&&c.getCount()!=0){
		c.SetCreature(c.getCount()-1);
		totalDeff=totalDeff-(c.getDeff()*bonusDeff);
		totalAttack=totalAttack-(c.getDeff()*bonusDeff);

	}
}


BlackDragon::~BlackDragon() {
	// TODO Auto-generated destructor stub
}

