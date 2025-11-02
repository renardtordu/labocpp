#include "Model.h"

namespace carconfig
{
	// constructeurs
	Model::Model()
	{
		cout << "conqtructeur"<<endl;
		power =0;
		basePrice = 0;
		name = nullptr;
		name=new char [20];
		strcpy(name, "Model sans nom");
		engine=Petrol;
	}

	Model::Model(const char* nom, int puissance, Engine moteur, float prix)
	{
		setPower(puissance);
		setEngine (moteur),
		setBasePrice(prix);
		name = nullptr;
		setName(nom);
	}
	Model::Model(const Model& M)
	{
		setPower(M.power);
		setEngine(M.engine);
		name = nullptr;
		setName(M.name);
		setBasePrice(M.basePrice);
	}
	Model::~Model()
	{
		cout <<endl<< "destructeur"<<endl;
		delete [] name;
	}


	// get/set

	int Model::getPower()
	{
		return power;
	}

	void Model::setPower(int val)
	{
		if(val >= 0)
		{
			power = val;
		}
	}

	Engine Model::getEngine()
	{
		return engine;
	}
	void Model::setEngine(Engine e)
	{
		engine = e;
	}
	float Model::getBasePrice()
	{
		return basePrice;
	}
	void Model::setBasePrice(float va)
	{
		basePrice = va;
	}
	const char* Model::getName()
	{
		return name;
	}
	void Model::setName (const char* nom)
	{
		delete name;
		name = new char[strlen(nom)+1];
	    strcpy(name,nom);
		
	}


	// autre fonction
	void Model::display()
	{
		cout << "puissance: " <<power<<endl<< "prix de base: "<<basePrice<<endl<<"nom: "<<name<<endl<< "type moteur: ";
		switch(engine)
		{
			case Petrol:
				cout << "essence";
				break;
			case Diesel:
				cout <<"Diesel";
				break;
			case Electric:
				cout << "Electrique";
				break;
			case Hybrid:
				cout << "Hybrid";
				break;
		}
		cout<<endl;
	}
}