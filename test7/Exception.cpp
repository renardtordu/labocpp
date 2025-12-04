#include "Exception.h"

Exception::Exception()
{
	message="erreur";
}
Exception::Exception(string e)
{
	setMessage(e);
}
void Exception::setMessage(string m)
{
	message=m;
}
string Exception::getMessage()const
{
	return message;
}
