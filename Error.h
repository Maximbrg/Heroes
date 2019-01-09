
#include <iostream>
using namespace std;
#ifndef ERROR_H_
#define ERROR_H_

class Error
{
public:
	Error(){}
	virtual void Handle()const = 0;
	virtual ~Error(){}
};
//////////////////////////////////////////////////////////
class ErrorInvalidName: public Error
{
public:
	ErrorInvalidName(): Error() {}
	virtual void Handle()const { cout << "invalid name\n"; };
	virtual ~ErrorInvalidName(){}
};



///////////////////////////////////


class ErrorNotEnoughMoney: public Error
{
public:
	ErrorNotEnoughMoney(): Error(){}
	virtual void Handle()const { cout << "You do not have enough gold"<< "\n"; };
	virtual ~ErrorNotEnoughMoney(){}
};

///////////////////////////////////////////////////////////
class ErrorNoSuchCreatureArmy: public Error
{
	string m_name;
public:
	ErrorNoSuchCreatureArmy(string name): Error(),m_name(name){}
	virtual void Handle()const { cout << m_name << " doesn't exist in the opponent's army"<< "\n"; };
	virtual ~ErrorNoSuchCreatureArmy(){}
};
class ErrorNoSuchCreature: public Error
{
	string m_name;
public:
	ErrorNoSuchCreature(string name): Error(),m_name(name){}
	virtual void Handle()const { cout << m_name << " is not a creature"<< "\n"; };
	virtual ~ErrorNoSuchCreature(){}
};

////////////////////////////////////////////////////////////
class ErrorInvalidHero: public Error
{
	string m_name;
public:
	ErrorInvalidHero(string name): Error(),m_name(name){}
	virtual void Handle()const { cout << m_name<< " is not a hero" << "\n"; };
	virtual ~ErrorInvalidHero(){}
};


#endif /* ERROR_H_ */


