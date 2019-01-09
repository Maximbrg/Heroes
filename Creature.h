/*
 * Creature.h
 *
 *  Created on: 3 Jan 2019
 *      Author: max
 */
#include <iostream>
#ifndef CREATURE_H_
#define CREATURE_H_

class Creature {
protected:
	int _attack;
	int _deff;
	int _cost;
	int _counter;
public:
	//constructors
	Creature();
	//getters
	 const int getAtack()const{return _attack;};
	 const int getCost()const{return _cost;};
	 const int getDeff()const{return _deff;};
	 const int getCount()const{return _counter;};
	//setters
	void SetCreature(const int num){_counter=num;};
	const void setCount(){ _counter--;};
	//func
	 const void print()const{std:: cout<<"Attack level: "<<_attack<<", Defense level: "<<_deff<<"\n";};
	//virtual
	virtual void Attack(Creature& c)=0;
	virtual ~Creature();
};

#endif /* CREATURE_H_ */
