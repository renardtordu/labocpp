#include "Employee.h"

const string Employee::ADMINISTRATIVE="Administratif";
const string Employee::SELLER="Vendeur";

Employee::Employee():Actor()
{
	password=nullptr;
	login=" ";
}
Employee::Employee(string l, string f, int i, string lo, string r):Actor(l,f,i)
{
	password=nullptr;
	this->setLogin(lo);
	this->setRole(r);
}
Employee::Employee(const Employee& e):Actor(e)
{
	setLogin(e.login);
	setRole(e.role);
	if(e.password != nullptr)
	{
		password = new string(*e.password);
	}
	else
		this->password = nullptr;
}
void Employee::resetPassword()
{
	if(password != nullptr)
		delete password;
	password=nullptr;
}
void Employee::setPassword(const string& e)
{
	if(password != nullptr)
		delete password;
	password=new string(e);
}
void Employee::setRole(const string r)
{
	role=r;
}
void Employee::setLogin(string l)
{
	login=l;
}
string Employee::getPassword()const
{
	if(password != nullptr)
		return *password;
	else
		return nullptr;
}
string Employee::getRole()const
{
	return role;
}
string Employee::getLogin()const
{
	return login;
}
string Employee::tuple()const
{
	return to_string(this->id)+";"+this->lastName+";"+this->firstName+";"+this->role;
}
string Employee::toString()const
{
	if(role==Employee::ADMINISTRATIVE)
		return"[A"+to_string(this->id)+"] "+lastName+" "+firstName;
	else
		return"[V"+to_string(this->id)+"] "+lastName+" "+firstName;
}
ostream& operator<<(ostream& o, const Employee& e)
{
	o<<e.tuple();
	return o;
}
Employee& Employee::operator=(const Employee& e)
{
	Actor::operator=(e);
	this->login=e.login;
	this->role=e.role;
	if(this->password != nullptr)
		delete this->password;
	if(e.password !=nullptr)
		this->password=new string(*e.password);
	else
		this->password=nullptr;

	return *this;
}
Employee::~Employee()
{
	cout<<"destructeur"<<endl;
	delete password;
}
