#include "AnyType.h"

const std::map<const AnyType::Type, const char* const> AnyType::TYPE_NAMES {
	{Type::BOOL, "bool"},
	{Type::CHAR, "char"},
	{Type::INT, "int"},
	{Type::UNSIGNED_INT, "unsigned int"},
	{Type::FLOAT, "float"},
	{Type::DOUBLE, "double"},
	{Type::NONE, "undefined type"}
};

AnyType::AnyType() : m_value(nullptr), m_type(Type::NONE) {}

AnyType::AnyType(const bool& value)
		: m_value(std::make_unique<Value>(Value{value}))
		, m_type(Type::BOOL) {}

AnyType::AnyType(const char& value)
		: m_value(std::make_unique<Value>(Value{value}))
		, m_type(Type::CHAR) {}

AnyType::AnyType(const int& value)
		: m_value(std::make_unique<Value>(Value{value}))
		, m_type(Type::INT) {}

AnyType::AnyType(const unsigned int& value)
		: m_value(std::make_unique<Value>(Value{value}))
		, m_type(Type::UNSIGNED_INT) {}

AnyType::AnyType(const float& value)
		: m_value(std::make_unique<Value>(Value{value}))
		, m_type(Type::FLOAT) {}

AnyType::AnyType(const double& value)
		: m_value(std::make_unique<Value>(Value{value}))
		, m_type(Type::DOUBLE) {}

AnyType::AnyType(const AnyType &obj)
{
	if (obj.m_type != Type::NONE)
		this->m_value = std::make_unique<Value>(*obj.m_value);
	else
		this->m_value = nullptr;

	this->m_type = obj.m_type;
}

AnyType::AnyType(AnyType &&obj) noexcept
{
	if (obj.m_type != Type::NONE)
		this->m_value = std::make_unique<Value>(std::move(*obj.m_value));
	else
		this->m_value = nullptr;

	this->m_type = std::move(obj.m_type);
}

AnyType::~AnyType()
{
	this->Destroy();
}

AnyType &AnyType::operator=(const bool& value)
{
	this->Destroy();
	this->m_value = std::make_unique<Value>(Value{value});
	this->m_type = Type::BOOL;
	return *this;
}

AnyType &AnyType::operator=(const char& value)
{
	this->Destroy();
	this->m_value = std::make_unique<Value>(Value{value});
	this->m_type = Type::CHAR;
	return *this;
}

AnyType &AnyType::operator=(const int& value)
{
	this->Destroy();
	this->m_value = std::make_unique<Value>(Value{value});
	this->m_type = Type::INT;
	return *this;
}

AnyType& AnyType::operator=(const unsigned int& value)
{
	this->Destroy();
	this->m_value = std::make_unique<Value>(Value{value});
	this->m_type = Type::UNSIGNED_INT;
	return *this;
}

AnyType &AnyType::operator=(const float& value)
{
	this->Destroy();
	this->m_value = std::make_unique<Value>(Value{value});
	this->m_type = Type::FLOAT;
	return *this;
}

AnyType &AnyType::operator=(const double& value)
{
	this->Destroy();
	this->m_value = std::make_unique<Value>(Value{value});
	this->m_type = Type::DOUBLE;
	return *this;
}

AnyType& AnyType::operator=(const AnyType &obj)
{
	if (this == &obj)
		return *this;

	this->Destroy();
	if (obj.m_type == Type::NONE)
		return *this;

	this->m_value = std::make_unique<Value>(*obj.m_value);
	this->m_type = obj.m_type;
	return *this;
}

AnyType& AnyType::operator=(AnyType &&obj) noexcept
{
	if (this == &obj)
		return *this;

	this->Destroy();
	if (obj.m_type == Type::NONE)
		return *this;

	this->m_value = std::make_unique<Value>(std::move(*obj.m_value));
	this->m_type = std::move(obj.m_type);
	return *this;
}

void AnyType::Destroy()
{
	this->m_value.reset();
	this->m_value = nullptr;
	this->m_type = Type::NONE;
}

void AnyType::Swap(AnyType &obj)
{
	if (this == &obj)
		return;

	this->m_value.swap(obj.m_value);
	std::swap(this->m_type, obj.m_type);
}

const char* AnyType::get_type_name() const noexcept
{
	return TYPE_NAMES.at(this->m_type);
}

bool AnyType::ToBool() const
{
	CheckTypeIs(Type::BOOL);
	return this->m_value->bool_;
}

char AnyType::ToChar() const
{
	CheckTypeIs(Type::CHAR);
	return this->m_value->char_;
}

int AnyType::ToInt() const
{
	CheckTypeIs(Type::INT);
	return this->m_value->int_;
}

unsigned int AnyType::ToUnsignedInt() const
{
	CheckTypeIs(Type::UNSIGNED_INT);
	return this->m_value->unsigned_int_;
}

float AnyType::ToFloat() const
{
	CheckTypeIs(Type::FLOAT);
	return this->m_value->float_;
}

double AnyType::ToDouble() const
{
	CheckTypeIs(Type::DOUBLE);
	return this->m_value->double_;
}

void AnyType::CheckTypeIs(Type&& type) const
{
	if (this->m_type != type)
		throw ExceptionType(TYPE_NAMES.at(type));
}
