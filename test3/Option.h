#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <string>
using namespace std;
namespace carconfig
{
	class Option
	{
	private:
		string code;
		string label;
		float price;

	public:

		string getCode()const;
		string getLabel()const;
		float getPrice()const;

		void setCode(string);
		void setLabel(string);
		void setPrice(float);

		Option();
		Option(string, string, float);
		Option(const Option&);

		void display();

		friend istream& operator>>(istream&, Option&);
		friend ostream& operator<<(ostream&, const Option&);
		Option operator--();
		Option operator--(int);

	};
}
#endif