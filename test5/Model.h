#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <cstring>
using namespace std;

namespace carconfig
{
	enum Engine{ Petrol, Diesel, Electric, Hybrid};
	class Model
	{
	private:
		int power;
		float basePrice;
		char *name;
		Engine engine;

	public:
		Model();
		~Model();

		int getPower();
		Engine getEngine();
		float getBasePrice()const;
		const char* getName();
		void setPower(int);
		void setEngine(Engine);
		void setBasePrice(float);
		void setName(const char*);
		Model(const char* nom, int puissance, Engine moteur, float prix);
		Model(const Model& M);


		void display();

		friend istream& operator>>(istream&, Model&);
		friend ostream& operator<<(ostream&, const Model&);
		
	};
}
#endif