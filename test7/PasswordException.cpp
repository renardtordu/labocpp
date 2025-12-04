#include "PasswordException.h"
const int PasswordException::INVALID_LENGTH = 0;
const int PasswordException::ALPHA_MISSING =1;
const int PasswordException::DIGIT_MISSING = 2;
const int PasswordException::NO_PASSWORD = 3;


PasswordException::PasswordException(int i,string p): Exception(p)
{
	setCode(i);
}
void PasswordException::setCode(int c)
{
	code = c;
}
int PasswordException::getCode()const
{
	return code;
}