#ifndef XMLFILESERIALIZERException_H
#define XMLFILESERIALIZERException_H
#include <iostream>
#include <string>
#include "Exception.h"
using namespace std;

class XmlFileSerializerException: public Exception
{
private:
	int code;
public:
	XmlFileSerializerException();
	XmlFileSerializerException(int, string);
	void setCode(int);
	int getCode()const;
	static const int NOT_ALLOWED;
	static const int FILE_NOT_FOUND;
	static const int END_OF_FILE;
};
#endif