#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;
#include "Actor.h"

class Employee:public Actor
{
public:
	static const string ADMINISTRATIVE;
	static const string SELLER;
private:
	string login;
	string role;
	string* password;
public:
	Employee();
	Employee(string, string, int, string, string);
	Employee(const Employee&);
	void resetPassword();
	void setPassword(const string&);
	void setRole(const string r);
	void setLogin(string l);
	string getPassword()const;
	string getRole()const;
	string getLogin()const;
	string tuple()const override;
	string toString()const override;
	friend ostream& operator<<(ostream&, const Employee&);
	Employee& operator=(const Employee&);
	~Employee();
};
#endif