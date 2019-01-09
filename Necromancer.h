/*
 * Necromancer.h
 *
 *  Created on: 4 Jan 2019
 *      Author: max
 */
#include "Hero.h"
#ifndef NECROMANCER_H_
#define NECROMANCER_H_

class Necromancer: public  Hero{
public:
	Necromancer(string name);
	void saveData(string path);
	void specalAbility(list<Hero*> players);
	virtual ~Necromancer();
};

#endif /* NECROMANCER_H_ */
