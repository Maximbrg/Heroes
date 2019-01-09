/*
 * Warrior.h
 *
 *  Created on: 4 Jan 2019
 *      Author: max
 */
#include "Hero.h"
#include <fstream>
#include <iostream>
#ifndef WARRIOR_H_
#define WARRIOR_H_

class Warrior: public  Hero{
public:
	Warrior(string name);
	void specalAbility(list<Hero*> players);
	void saveData(string path);
	virtual ~Warrior();
};

#endif /* WARRIOR_H_ */
