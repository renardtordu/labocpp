#include "XmlFileSerializerException.h"
const int XmlFileSerializerException::NOT_ALLOWED = 0;
const int XmlFileSerializerException::FILE_NOT_FOUND = 1;
const int XmlFileSerializerException::END_OF_FILE = 2;

XmlFileSerializerException::XmlFileSerializerException()
{
	code=0;
}
XmlFileSerializerException::XmlFileSerializerException(int c, string s): Exception(s)
{
	setCode(c);
}
void XmlFileSerializerException::setCode(int c)
{
	code = c;
}
int XmlFileSerializerException::getCode()const
{
	return code;
}