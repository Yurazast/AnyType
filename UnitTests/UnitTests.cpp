#include "pch.h"
#include "../AnyType/ExceptionType.h"
#include "../AnyType/AnyType.h"

TEST(AnyTypeTest, NoneTypeName) {
	AnyType anyType;

	ASSERT_STREQ(anyType.get_type_name(), "undefined type");
}

TEST(AnyTypeTest, CharAnyType) {
	AnyType anyType('t');

	ASSERT_STREQ(anyType.get_type_name(), "char");
	ASSERT_EQ(anyType.ToChar(), 't');
}

TEST(AnyTypeTest, AnyTypeAssignment) {
	AnyType anyType(1.2f);

	anyType = true;

	ASSERT_STREQ(anyType.get_type_name(), "bool");
	ASSERT_TRUE(anyType.ToBool());
}

TEST(AnyTypeTest, MultipleAssignment) {
	AnyType anyType;

	anyType = 2;
	anyType = '2';
	anyType = 7.9235f;

	ASSERT_STREQ(anyType.get_type_name(), "float");
	ASSERT_FLOAT_EQ(anyType.ToFloat(), 7.9235f);
}

TEST(AnyTypeTest, CopyConstructor) {
	AnyType first_anyType(275972u);
	AnyType second_anyType(first_anyType);

	ASSERT_STREQ(second_anyType.get_type_name(), "unsigned int");
	ASSERT_EQ(second_anyType.ToUnsignedInt(), 275972u);
}

TEST(AnyTypeTest, MoveConstructor) {
	AnyType first_anyType(false);
	AnyType second_anyType(std::move(first_anyType));

	ASSERT_STREQ(second_anyType.get_type_name(), "bool");
	ASSERT_FALSE(second_anyType.ToBool());
}

TEST(AnyTypeTest, CopyAssignment) {
	AnyType first_anyType('8');
	AnyType second_anyType;

	second_anyType = first_anyType;

	ASSERT_STREQ(second_anyType.get_type_name(), "char");
	ASSERT_EQ(second_anyType.ToChar(), '8');
}

TEST(AnyTypeTest, MoveAssignment) {
	AnyType first_anyType;
	AnyType second_anyType(238);

	second_anyType = std::move(first_anyType);

	ASSERT_STREQ(second_anyType.get_type_name(), "undefined type");
	ASSERT_ANY_THROW(second_anyType.ToInt());
}

TEST(AnyTypeTest, CorrectCast) {
	AnyType anyType(25u);

	ASSERT_NO_THROW(anyType.ToUnsignedInt());
}

TEST(AnyTypeTest, IncorrectCast) {
	AnyType anyType('*');

	ASSERT_ANY_THROW(anyType.ToDouble());
}

TEST(AnyTypeTest, SwapTwoAnytypes) {
	AnyType first_anyType(2.378592375);
	AnyType second_anyType(6);

	first_anyType.Swap(second_anyType);

	ASSERT_STREQ(first_anyType.get_type_name(), "int");
	ASSERT_STREQ(second_anyType.get_type_name(), "double");
	ASSERT_EQ(first_anyType.ToInt(), 6);
	ASSERT_DOUBLE_EQ(second_anyType.ToDouble(), 2.378592375);
}

TEST(ExceptionTypeTest, ExceptionMessage)
{
	ExceptionType exceptionType("unsigned int");

	ASSERT_STREQ(exceptionType.what(), "ExceptionType: bad cast to unsigned int");
}

std::int32_t main(std::int32_t argc, char** const argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}