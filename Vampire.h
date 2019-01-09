/*
 * Vampire.h
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */
#include "Creature.h"
#ifndef VAMPIRE_H_
#define VAMPIRE_H_

class Vampire: public Creature{
public:
	Vampire();
	void Attack(Creature& c);
	virtual ~Vampire();
};

#endif /* VAMPIRE_H_ */
