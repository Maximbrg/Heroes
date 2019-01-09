/*
 * Wizard.h
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */
#include "Creature.h"
#ifndef WIZARD_H_
#define WIZARD_H_

class Wizard:public Creature {
public:
	Wizard();
	void Attack(Creature& c);
	virtual ~Wizard();
};

#endif /* WIZARD_H_ */
