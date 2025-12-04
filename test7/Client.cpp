#include "Client.h"

Client::Client():Actor()
{
	gsm = "+32";
}
Client::Client(string l,string f,int i,string g):Actor(l,f,i)
{
	this->setGsm(g);
}
Client::Client(const Client& c):Actor(c)
{
	setGsm(c.gsm);
}
void Client::setGsm(string g)
{
	gsm = g;
}
string Client::getGsm()const
{
	return gsm;
}
string Client::tuple()const
{
	return to_string(this->id)+";"+this->lastName+";"+this->firstName+";"+this->gsm;
}
string Client::toString()const
{
	return"[C"+to_string(this->id)+"] "+lastName+" "+firstName;
}
ostream& operator<<(ostream& o, const Client& c)
{
	o<<"<Client>"<<endl;
	o<<"<lastName>"<<endl;
	o<<c.lastName<<endl;
	o<<"</lastName>"<<endl;
	o<<"<firstName>"<<endl;
	o<<c.firstName<<endl;
	o<<"</firstName>"<<endl;
	o<<"<id>"<<endl;
	o<<c.id<<endl;
	o<<"</id>"<<endl;
	o<<"<gsm>"<<endl;
	o<<c.gsm<<endl;
	o<<"</gsm>"<<endl;
	o<<"</Client>";
	return o;
}
istream& operator>>(istream& i, Client& c)
{
	string ligne;
	getline(i,ligne);//<--balise Client
	getline(i,ligne);
	getline(i,ligne);
	c.setLastName(ligne);
	getline(i,ligne);
	getline(i,ligne);
	getline(i,ligne);
	c.setFirstName(ligne);
	getline(i,ligne);
	getline(i,ligne);
	getline(i,ligne);
	c.setId(stoi(ligne));
	getline(i,ligne);
	getline(i,ligne);
	getline(i,ligne);
	c.setGsm(ligne);
	getline(i,ligne);
	getline(i,ligne);// /Model
	return i;
}