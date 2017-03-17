#include "TInteger.h"
#include "Exception.h"

void main()
{
	long long int longLen = 238748364799;
	long long int shortLen = -3147490364799;
	try
	{
		TInteger x(longLen);            
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	TInteger a(2);
	try
	{
		a = shortLen;
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	TInteger b = 89;
	TInteger c(a);
	try
	{
		b += longLen;
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		TInteger c = b - shortLen;
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c -= longLen;
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c = longLen;
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c *= longLen;
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		c = b * shortLen;
	}
	catch (TCastException & e)
	{
		std::cout << e.what() << std::endl;
	}


	int num = 120;
	TInteger d = num;
	d++;
	std::cout << d << std::endl;
	TInteger f = d % 25;
	if(f == 20 ) std::cout << f << std::endl;
	d /= f;
	if (d < 99999) std::cout << d << std::endl;
	f = d * d;
	std::cout << f << std::endl;
	f = d * 45;;
	if ( f != longLen) std::cout << f << std::endl;
	d = f + 2016;
	if (d == (f + 2016)) std::cout << d << std::endl;
	f = d - 34;
	if (f > 2) std::cout << f << std::endl;
	a = f / 2;
	if (a < f)  std::cout << a << std::endl;
	system("pause");
}
