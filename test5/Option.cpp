#include "Option.h"

namespace carconfig
{
	Option::Option()
	{
		code = "00000000";
		label = "unknown";
		price = 0;
	}

	string Option::getCode() const
	{
		return code;
	}

	string Option::getLabel()const
	{
		return label;
	}
	float Option::getPrice()const
	{
		return price;
	}

	void Option::setCode(string c)
	{
		if(c.length()!=4)
		{
			throw OptionException("erreur code pas = a 4");
		}
		code = c;
	}
	void Option::setLabel(string l)
	{
		if(l.length()==0)
		{
			throw OptionException("intituler doit avoir au moins une lettre");
		}
		label = l;
	}
	void Option::setPrice(float p)
	{
		if(p < 0)
		{
			throw OptionException("le prix ne doit pas etre negatif");
		}
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

	istream& operator>>(istream& i, Option& o)
	{
		string c, l;
		float p;
		i>>c;
		if(c.length()!=4)
		{
			throw OptionException("erreur code pas = a 4");
		}
		i.ignore();
		getline(i, l);
		if(l.length()==0)
		{
			throw OptionException("intituler doit avoir au moins une lettre");
		}
		i>>p;
		i.ignore();
		if(p < 0)
		{
			throw OptionException("le prix ne doit pas etre negatif");
		}
		o.code = c;
		o.label = l;
		o.price = p;
		return i;
	}
	ostream& operator<<(ostream& o, const Option& p)
	{
		o<<"code = "<<p.code<<endl<<"label = "<<p.label<<endl<<"price = "<<p.price<<endl;
		return o;
	}

	Option Option:: operator--()
	{
		(*this).price-=50;
		if(price < 0)
		{
			throw OptionException("le prix ne doit pas etre negatif");
		}
		return *this;
	}
	Option Option:: operator-- (int)
	{
		Option tmp(*this);
		price-=50;
		if(price < 0)
		{
			throw OptionException("le prix ne doit pas etre negatif");
		}
		return tmp;
	}
}