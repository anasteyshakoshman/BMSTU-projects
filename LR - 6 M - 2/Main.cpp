#include "Header.h"


int main()
{

	try
	{
		FromString <bool>("hw");    //неизвестное значение
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

	bool log = FromString <bool>("TRUE");
	if (log) std::cout << "TRUE" << std::endl;

	try
	{
		FromString <int>("2147483647999");          //превышения максимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		FromString <int>("-2147483647999");      //превышение  предела минимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		FromString <int>("аааааа");    //неизвестное значение
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << FromString <int>("-956") << std::endl;   //выведет -956


	try
	{
		FromString <float>("21474836479.9999");         //превышения максимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		FromString <float>("-21474836479.9999");        //превышение  предела минимума
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		FromString <float>("ffff");           //неизвестное значение
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << FromString <float>("-89,567") << std::endl;   //выведет -89,567	

	system("pause");
	return 0;
}
