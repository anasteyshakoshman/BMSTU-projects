#include "Header.h"

int main()
{
	try
	{
		boolFromString("hw");    //неизвестное значение
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

    
	try
	{
		intFromString("2147483647999");          //превышения максимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

 
	try
	{
		intFromString("-2147483647999");      //превышение  предела минимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		  intFromString("аааааа");    //неизвестное значение
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}


	int num = 0;  
	try
	{
		num = intFromString("-956");      //выведет -956
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << num << std::endl;


	try
	{
		floatFromString("21474836479.9999");         //превышения максимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		floatFromString("-21474836479.9999");        //превышение  предела минимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		floatFromString("ffff");           //неизвестное значение
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}


	float number = 0;
	try
	{
		number = floatFromString("-89,567");     //выведет -89,567
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << number << std::endl;

	system("pause");
	return 0;
}
