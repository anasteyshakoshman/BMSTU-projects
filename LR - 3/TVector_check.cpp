#include "TVector.h"

int main()
{
	int n = 0;
	std::cout << "Enter quantity of elemets in massiv: ";
	std::cin >> n;
	double * mus = new double[n];
	for (int i = 0; i < n; i++)
	{
		mus[i] = (double)rand() / 100.00f;
	}
	TVector vector1(mus, n);           //вызов конструктора с параметром const double * const mus
	std::cout << "Vector 1: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << vector1[i] << "  ";        //проверка оператора []
	}
	TVector vector2(vector1);    //вызов конструктора с параметром const TVector & vec  
	TVector vector3;           //вызов конструктора без параметров
	double Chislo = 1.5;
	if (vector1[1] = vector2[1])  vector3 = Chislo * vector1;   //проверка работы операторв * с параметрами const double chislo и const TVector & vec
	std::cout << std::endl << "Vector 3 : " << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << vector3[i] << "  ";       
	}
	delete [] mus;
	system("pause");
	return 0;
}
