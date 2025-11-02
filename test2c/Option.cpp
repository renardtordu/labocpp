#include "Option.h"

namespace carconfig
{
	Option::Option()
	{
		code = "00000000";
		label = "unknown";
		price = 0;
	}

	string Option::getCode()
	{
		return code;
	}

	string Option::getLabel()
	{
		return label;
	}
	float Option::getPrice()
	{
		return price;
	}

	void Option::setCode(string c)
	{
		code = c;
	}
	void Option::setLabel(string l)
	{
		label = l;
	}
	void Option::setPrice(float p)
	{
		price = p;
	}

	Option::Option(string c, string l, float p)
	{
		setCode(c);
		setLabel(l);
		setPrice(p);
	}
	Option::Option(const Option& o)
	{
		setCode(o.code);
		setLabel(o.label);
		setPrice(o.price);
	}

	void Option::display()
	{
		cout<<"code = "<<code<<endl<<"label = "<<label<<endl<<"price = "<<price<<endl;
	}
}