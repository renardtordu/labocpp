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
		string ligne;
		getline(i,ligne);//<--balise Option
		getline(i,ligne); // code
		getline(i,ligne);//variable code
		o.setCode(ligne);
		getline(i,ligne);// /code
		getline(i,ligne);//label
		getline(i,ligne);//variable label
		o.setLabel(ligne);
		getline(i,ligne);// /label
		getline(i,ligne);//prix
		getline(i,ligne); // variable prix
		o.setPrice(stof(ligne));
		getline(i,ligne);// /prix
		getline(i,ligne);// /Option
		return i;
	}
	ostream& operator<<(ostream& o, const Option& p)
	{
		o<<"<Option>"<<endl;
		o<<"<code>"<<endl;
		o<<p.code<<endl;
		o<<"</code>"<<endl;
		o<<"<label>"<<endl;
		o<<p.label<<endl;
		o<<"</label>"<<endl;
		o<<"<price>"<<endl;
		o<<p.price<<endl;
		o<<"</price>"<<endl;
		o<<"</Option>"<<endl;		
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