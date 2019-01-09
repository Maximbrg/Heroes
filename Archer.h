/*
 * Archer.h
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */
#include "Creature.h"
#ifndef ARCHER_H_
#define ARCHER_H_

class Archer: public Creature {
public:
	Archer();
	void Attack(Creature& c);
	virtual ~Archer();
};

#endif /* ARCHER_H_ */
