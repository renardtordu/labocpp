#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Model.h"

class Car
{
private:
	string name;
	Model model;

public:
	Car();
	Car(string, Model);
	Car(const Car& c);
	void setName(string n);
	string getName() const;
	Model getModel() const;
	void setModel(Model m);
	void display();
};
#endif