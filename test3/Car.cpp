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
	float Car::getPrice()const
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
			if(option[i] != nullptr && option[i]->getCode() == r)
			{
				delete option[i];
				option[i] = nullptr;
				return;
			}
		}
		cout<<"n'existe pas"<<endl;
	}
	Car& Car:: operator=(const Car& c)
	{
		if(this==&c)
		{
			return *this;
		}
		int i;
		for(i= 0; i<5;i++)
		{
			if(option[i] != nullptr)
			{
				option[i] = nullptr;
			}
		}
		setName(c.name);
		setModel(c.model);
		for(i = 0; i < 5; i++)
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
		return *this;
	}

	Car Car:: operator+(const Option& o)
	{
		Car res(*this);
		res.addOption(o);
		return res;
	}
	Car operator+(const Option& o, const Car& c)
	{
		Car res(c);
		res.addOption(o);
		return res;
	}
	Car Car:: operator-(const Option& o) const
	{
		Car res(*this);
		res.removeOption(o.getCode());
		return res;
	}
	Car Car:: operator-(const string r)
	{
		Car res(*this);
		res.removeOption(r);
		return res;
	}

	bool Car::operator<(const Car& c)const
	{
		return this-> getPrice()< c.getPrice();
	}
	bool Car::operator>(const Car& c)const
	{
		return this-> getPrice()>c.getPrice();
	}
	bool Car::operator==(const Car& c)const
	{
		return this-> getPrice() ==c.getPrice();
	}
	ostream& operator<<(ostream& o, const Car& c)
	{
		o<<c.name<<endl<<c.model<<endl;
		for (int i = 0; i < 5; i++)
		{
			if(c.option[i] != nullptr)
			{
				o<<i+1<<endl;
				o<<c.option[i]->getCode()<<endl<<c.option[i]->getLabel()<<endl<<c.option[i]->getPrice()<<endl;
			}
		}
		return o;
	}
	Option* Car::operator[](int i)
	{
		if(i >= 0 && i < 5)
			return option[i];
		else
			return NULL;
	}

}