#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Model.h"
#include "Option.h"

using namespace carconfig;
using namespace std;

class Car
{
private:
	string name;
	Model model;
	Option* option[5];

public:
	void removeOption(string);
	float getPrice();
	void addOption(const Option&);
	Car();
	Car(string, Model);
	Car(const Car& c);
	void setName(string n);
	string getName() const;
	Model getModel() const;
	void setModel(Model m);
	~Car();
	void display();
};
#endif