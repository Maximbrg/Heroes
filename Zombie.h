/*
 * Zombie.h
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */
#include "Creature.h"
#ifndef ZOMBIE_H_
#define ZOMBIE_H_

class Zombie: public Creature{
public:
	Zombie();
	void Attack(Creature& c);
	virtual ~Zombie();
};

#endif /* ZOMBIE_H_ */
