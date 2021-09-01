#pragma once
#include <typeinfo>
#include <string>

class ExceptionType : public std::bad_cast
{
public:
	explicit ExceptionType(const char* const msg);
	const char* what() const noexcept override;

private:
	std::string message = "ExceptionType: bad cast to ";
};
