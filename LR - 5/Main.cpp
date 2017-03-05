#include "TPair.h"
#include "TFraction.h"


void main()
{
	TPair a;
	std::cout << "Enter pair a" << std::endl;             //проверка метода ввода базового класса
	std::cin >> a;                                        
	TPair b(17, 25);
	std::cout << "\nPair b \n" << b;                      //проверка метода вывода базового класса

	if (a == b) std::cout << "\na == b" << std::endl;       //проверка метода сравнения == базового класса
	if (a > b) std::cout << "\na > b" << std::endl;         //проверка метода сравнения > базового класса
	if (a < b) std::cout << "\na < b" << std::endl;         //проверка метода сравнения < базового класса
	if (b != a) std::cout << "\nb != a" << std::endl;       //проверка метода сравнения != базового класса

	TFraction c;
	std::cout << "\nEnter fraction c" << std::endl;         //проверка метода ввода производного класса
	std::cin >> c;                                         
	TFraction d(25, 100);
	std::cout << "\nFraction d \n" << b;                  //проверка метода вывода производного класса

	if (c == d) std::cout << "\nc == d" << std::endl;       //проверка метода сравнения == производного класса
	if (c > d) std::cout << "\nc > d" << std::endl;         //проверка метода сравнения > производного класса
	if (c < d) std::cout << "\nc < d" << std::endl;         //проверка метода сравнения < производного класса
	if (c != d) std::cout << "\nc != d" << std::endl;       //проверка метода сравнения != производного класса
	
	system("pause");
}
