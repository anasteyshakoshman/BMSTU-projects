//Реализовать ПО, которые вычисляет С(n, k) используя многопоточное 
//программирование.Для работы с большими числами можно использовать InfInt
#include <iostream>
#include "InfInt.h"
#include <thread>
#include <future>

InfInt factorial(InfInt a)
{
	InfInt a_fac = 1, tmp = 2;
	while (tmp <= a)
	{
		a_fac *= tmp;
		++tmp;
	}
	return a_fac;
}


InfInt C(InfInt n, InfInt k)
{
	if (k > n) return 0;
	std::future<InfInt> a = std::async(factorial, n);
	InfInt a_int = a.get();
	std::future<InfInt> b = std::async(factorial, k);
	InfInt b_int = b.get();
	std::future<InfInt> d = std::async(factorial, n - k);
	InfInt d_int = d.get();
	return InfInt(a_int / (b_int * d_int));
}

void main()
{
	InfInt n = 1500, k = 800, c = C(n, k);   
	std::cout << c << std::endl;
	system("pause");
}



