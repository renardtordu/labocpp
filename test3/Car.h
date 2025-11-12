#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Model.h"
#include "Option.h"

using namespace carconfig;
using namespace std;
namespace carconfig
{
	class Car
	{
	private:
		string name;
		Model model;
		Option* option[5];

	public:
		void removeOption(string);
		float getPrice() const;
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
		Car& operator=(const Car&);
		Car operator+(const Option&);
		friend Car operator+(const Option&, const Car&);
		friend ostream& operator<<(ostream&, const Car&);
		Car operator-(const Option&) const;
		Car operator-(const string);
		bool operator<(const Car&)const;
		bool operator>(const Car&)const;
		bool operator==(const Car&)const;
		Option* operator[](int);
	};
}
#endif