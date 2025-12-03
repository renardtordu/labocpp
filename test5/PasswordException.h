#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H
#include <iostream>
#include <string>
#include "Exception.h"
using namespace std;

class PasswordException:public Exception
{
private:
	int code;
public:
	PasswordException();
	PasswordException(int,string);
	static const int INVALID_LENGTH;
	static const int ALPHA_MISSING;
	static const int DIGIT_MISSING;
	static const int NO_PASSWORD;
	void setCode(int);
	int getCode()const;
};
#endif