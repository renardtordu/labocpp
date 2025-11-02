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

		string getCode();
		string getLabel();
		float getPrice();

		void setCode(string);
		void setLabel(string);
		void setPrice(float);

		Option();
		Option(string, string, float);
		Option(const Option&);

		void display();

	};
}