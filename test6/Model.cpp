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
	void Model::setEngine(int e)
	{
		switch(e)
		{
			case 0: 
                engine = Petrol; 
                break;
            case 1: 
                engine = Diesel;
                break;
            case 2: 
                engine = Electric;
                break;
            case 3: 
                engine = Hybrid;
                break;
            default: 
                engine = Petrol;
        }
	}
	float Model::getBasePrice()const
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
		if(name!=nullptr)
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

	istream& operator>>(istream& i, Model& m)
	{
		string ligne;
		getline(i,ligne);//<--balise Model
		getline(i,ligne);
		getline(i,ligne);
		m.setName(ligne.c_str());
		getline(i,ligne);
		getline(i,ligne);
		getline(i,ligne);
		m.setPower(stoi(ligne));
		getline(i,ligne);
		getline(i,ligne);
		getline(i,ligne);
		m.setEngine(stoi(ligne));
		getline(i,ligne);
		getline(i,ligne);
		getline(i,ligne);
		m.setBasePrice(stof(ligne));
		getline(i,ligne);
		getline(i,ligne);// /Model
		return i;
	}
	ostream& operator<<(ostream& o, const Model& m)
	{
		o<<"<Model>"<<endl;
		o<<"<name>"<<endl;
		o<<m.name<<endl;
		o<<"</name>"<<endl;
		o<<"<power>"<<endl;
		o<<m.power<<endl;
		o<<"</power>"<<endl;
		o<<"<engine>"<<endl;
		o<<m.engine<<endl;
		o<<"</engine>"<<endl;
		o<<"<basePrice>"<<endl;
		o<<m.basePrice<<endl;
		o<<"</basePrice>"<<endl;
		o<<"</Model>"<<endl;
		return o;
	}
	string Model::toString()const
	{
		return string(this->name)+" "+ to_string(this->power) + " " + enginetoString(this->engine) + " " + to_string(this->basePrice);
	}
	string Model::enginetoString(Engine e) const
    {
        switch(e)
        {
            case Petrol:
                return "Petrol";
            case Diesel:
                return "Diesel";
            case Electric:
                return "Electric";
            case Hybrid:
                return "Hybrid";
            default: 
                return "Inconnu";
        }
    }

}