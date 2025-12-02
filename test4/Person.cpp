#include "Person.h"

Person::Person()
{
	firstName="Saidou";
	lastName="Bah";
}
Person::Person(string l, string f)
{
	setLastName(l);
	setFirstName(f);
}
Person::Person(const Person& p)
{
	setLastName(p.lastName);
	setFirstName(p.firstName);
}
void Person::setLastName(const string l)
{
	lastName=l;
}
void Person::setFirstName(const string f)
{
	firstName=f;
}
string Person::getLastName()const
{
	return lastName;
}
string Person::getFirstName()const
{
	return firstName;
}
Person& Person::operator=(const Person& p)
{
	this->firstName=p.firstName;
	this->lastName=p.lastName;
	return *this;
}
istream& operator>>(istream& i, Person& p)
{
	string l, f;
	getline(i,l);
	getline(i, f);
	p.firstName=f;
	p.lastName=l;
	return i;
}
ostream& operator<<(ostream& o, const Person& p)
{
	o<<endl<<"Prenom: "<<p.firstName<<endl<<"Nom: "<<p.lastName<<endl;
	return o;
}

Person::~Person()
{
	cout<<"destructeur de personne"<<endl;
}