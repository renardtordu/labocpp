#ifndef ACTOR_H
#define ACTOR_H
#include <iostream>
#include <string>
using namespace std;
#include "Person.h"

class Actor: public Person
{
protected:
	int id;
public:
	Actor();
	Actor(string, string, int);
	Actor(const Actor&);
	void setId(int);
	int getId()const;
	virtual ~Actor() = default;
	virtual string tuple()const=0;
	virtual string toString()const=0;
};
#endif