#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person();
	Person(string, string);
	Person(const Person&);
	void setLastName(const string);
	void setFirstName(const string);
	string getLastName()const;
	string getFirstName()const;
	Person& operator=(const Person&);
	friend istream& operator>>(istream&, Person&);
	friend ostream& operator<<(ostream&, const Person&);
	~Person();
protected:
	string lastName;
	string firstName;
	
};
#endif