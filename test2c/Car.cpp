#include "Car.h"
#include <cstring>

namespace carconfig
{
	Car::Car()
	{
		name = "model sans Nom";
		model.setName("pas de nom");
		model.setPower(0);
		model.setEngine(Engine::Petrol);
		model.setBasePrice(0);
		for(int i = 0; i < 5; i++)
		{
			option[i] = nullptr;
		}
	}
	Car::Car(string n, Model m)
	{
		setName(n);
		setModel(m);
		for(int i = 0; i < 5; i++)
		{
			option[i] = nullptr;
		}
	}
	Car::Car(const Car& c)
	{
		setName(c.name);
		setModel(c.model);
		for(int i = 0; i < 5; i++)
		{
			if(c.option[i] != nullptr)
			{
				option[i] = new Option(*c.option[i]);
			}
			else
			{
				option[i] = nullptr;
			}
		}
	}

	void Car::display()
	{
		cout<<name<<endl;
		model.display();
		bool vrai = false;

		for(int i = 0; i < 5; i++)
		{
			if(option[i] != nullptr)
			{
				option[i]-> display();
				vrai = true;
			}
		}
		if(!vrai)
		{
			cout<<"pas d'option"<<endl;
		}
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
	void Car::addOption(const Option& o)
	{
		for(int i = 0; i < 5; i++)
		{
			if(option[i] == nullptr)
			{
				option[i] = new Option(o);
				return;
			}
		}
		cout<<"impossible plus de 5"<<endl;
	}
	Car::~Car()
	{
		for(int i = 0; i < 5; i++)
		{
			delete option[i];
			option[i] = nullptr;
		}
	}
	float Car::getPrice()
	{
		float sum = model.getBasePrice();
		for(int i = 0; i < 5; i++)
		{
			if(option[i] != nullptr)
			{
				sum += option[i]->getPrice();
			}
		}
		return sum;
	}
	void Car::removeOption(string r)
	{
		for(int i = 0; i < 5; i++)
		{
			if(option[i]->getCode() == r)
			{
				delete option[i];
				option[i] = nullptr;
				return;
			}
		}
		cout<<"n'existe pas"<<endl;
	}
}