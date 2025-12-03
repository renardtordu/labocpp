#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
using namespace std;
#include "Actor.h"

class Client:public Actor
{
private:
	string gsm;
public:
	Client();
	Client(string,string,int,string);
	Client(const Client&);
	void setGsm(string);
	string getGsm()const;
	string tuple()const override;
	string toString()const override;
	friend ostream& operator<<(ostream&, const Client&);
};
#endif