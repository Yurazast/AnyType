#pragma once
#include <memory>
#include "ExceptionType.h"

class AnyType
{
public:
	explicit AnyType();
	explicit AnyType(const bool& value);
	explicit AnyType(const char& value);
	explicit AnyType(const int& value);
	explicit AnyType(const unsigned int& value);
	explicit AnyType(const float& value);
	explicit AnyType(const double& value);
	explicit AnyType(const AnyType& obj);
	explicit AnyType(AnyType&& obj) noexcept;
	~AnyType();
	AnyType& operator=(const bool& value);
	AnyType& operator=(const char& value);
	AnyType& operator=(const int& value);
	AnyType& operator=(const unsigned int& value);
	AnyType& operator=(const float& value);
	AnyType& operator=(const double& value);
	AnyType& operator=(const AnyType& obj);
	AnyType& operator=(AnyType&& obj) noexcept;
	void Destroy();
	void Swap(AnyType& obj);
	const char* TypeName() const noexcept;
	bool ToBool() const;
	char ToChar() const;
	int ToInt() const;
	unsigned int ToUnsignedInt() const;
	float ToFloat() const;
	double ToDouble() const;

private:
	union Value
	{
		bool bool_;
		char char_;
		int int_;
		unsigned int unsigned_int_;
		float float_;
		double double_;

		Value(bool b) : bool_(b) {}
		Value(char c) : char_(c) {}
		Value(int i) : int_(i) {}
		Value(unsigned int u) : unsigned_int_(u) {}
		Value(float f) : float_(f) {}
		Value(double d) : double_(d) {}
	};

	enum class Type : std::size_t
	{
		BOOL,
		CHAR,
		INT,
		UNSIGNED_INT,
		FLOAT,
		DOUBLE,
		NONE
	};

	std::unique_ptr<Value> m_value;
	Type m_type;

	static const char* const TYPE_NAMES[];
};
