/*
 * Thief.h
 *
 *  Created on: 4 Jan 2019
 *      Author: max
 */

#include "Hero.h"
#ifndef THIEF_H_
#define THIEF_H_

class Thief:public Hero {
private:
	 Hero* special_compare(list<Hero*> players,string name);
public:
	Thief(string name);
	void saveData(string path);
	void specalAbility(list<Hero*> players);
	virtual ~Thief();
};

#endif /* THIEF_H_ */
