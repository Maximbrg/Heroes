/*
 * BlackDragon.h
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */
#include "Creature.h"
#ifndef BLACKDRAGON_H_
#define BLACKDRAGON_H_

class BlackDragon: public Creature{

public:
	BlackDragon();
	void Attack(Creature& c);
	virtual ~BlackDragon();
};

#endif /* BLACKDRAGON_H_ */
