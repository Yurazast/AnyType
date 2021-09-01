#include "ExceptionType.h"

ExceptionType::ExceptionType(const char* const msg)
{
	this->message += msg;
}

const char* ExceptionType::what() const noexcept
{
	return message.c_str();
}
