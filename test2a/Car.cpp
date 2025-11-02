#include "Car.h"
#include <cstring>

Car::Car()
{
	name = "model sans Nom";
	model.setName("pas de nom");
	model.setPower(0);
	model.setEngine(Engine::Petrol);
	model.setBasePrice(0);
}
Car::Car(string n, Model m)
{
	setName(n);
	setModel(m);
}
Car::Car(const Car& c)
{
	setName(c.name);
	setModel(c.model);
}

void Car::display()
{
	cout<<name<<endl;
	model.display();
}
void Car::setModel(Model m)
{
	model.setName(m.getName());
	model.setPower(m.getPower());
	model.setEngine(m.getEngine());
	model.setBasePrice(m.getBasePrice());
}
void Car::setName(string n)
{
	name = n;
}
string Car::getName()const
{
	return name;
}
Model Car::getModel()const
{
	return model;
}