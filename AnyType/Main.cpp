#include <iostream>
#include "AnyType.h"

int main()
{
	AnyType second_anyType(2.2);
	second_anyType = '~';

	AnyType first_anyType(8.0);
	first_anyType = 0.931f;

	std::cout << "Before swap:" << std::endl;
	std::cout << "first_anyType = " << first_anyType.ToFloat() << ", " << first_anyType.get_type_name() << std::endl;
	std::cout << "second_anyType = " << second_anyType.ToChar() << ", " << second_anyType.get_type_name() << std::endl;

	first_anyType.Swap(second_anyType);
	
	std::cout << "\nAfter swap:" << std::endl;
	std::cout << "first_anyType = " << first_anyType.ToChar() << ", " << first_anyType.get_type_name() << std::endl;
	std::cout << "second_anyType = " << second_anyType.ToFloat() << ", " << second_anyType.get_type_name() << std::endl;

	AnyType anyType(5u);

	try
	{
		std::cout << "\nTrying cast to unsigned int: " << std::endl;
		std::cout << "Stored value = " << anyType.ToUnsignedInt() << std::endl;

		std::cout << "\nTrying cast to double: " << std::endl;
		std::cout << "Stored value = " << anyType.ToDouble() << std::endl;
	}
	catch (const std::bad_cast& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "Unexpected error!" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
