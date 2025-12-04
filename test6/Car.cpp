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
			else if(option[i] != nullptr)
			{
				if(option[i]->getCode() == o.getCode())
					throw OptionException("l'option existe deja");
			}
		}
		throw OptionException("impossible plus de 5");
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
		throw OptionException("n'existe pas");
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
		o<<"<Car>"<<endl;
		o<<"<name>"<<endl;
		o<<c.name<<endl;
		o<<"</name>"<<endl;
		o<<c.model;
		o<<"<options>"<<endl;
		for(int i =0; i<5;i++)
		{
			if(c.option[i]!=nullptr)
				o<<*c.option[i];
		}
		o<<"</options>"<<endl;
		o<<"</Car>"<<endl;
		return o;
	}
	istream& operator>>(istream& i, Car& c)
	{
		string ligne;
		getline(i,ligne);//<--balise Model
		getline(i,ligne);
		getline(i,ligne);
		c.setName(ligne);
		getline(i,ligne);
		i>>c.model;
		getline(i,ligne);
		int id =0;
		while(id<5)
		{
			streampos p = i.tellg();
			getline(i,ligne);
			if(ligne == "</options>") break;
			i.seekg(p);
			c.option[id] = new Option;
			i>>*c.option[id];
			id++;
		}
		getline(i,ligne);
		return i;
	}
	Option* Car::operator[](int i)
	{
		if(i <= 0 || i > 6)
		{
			throw OptionException("erreur indice doit etre entre 1 et 6");
		}
		return option[i];
	}

}