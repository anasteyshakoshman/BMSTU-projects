#include "TString.h"

int main()
{
	TString line1("Hello world!    ");                                   //вызывается конструктор с параметром const * char
	std::cout << line1 << std::endl;
	if (line1.Empty())  std::cout << "Empty" << std::endl;                   //проверка логической функции empty
	else        std::cout << "The line isn't empty" << std::endl;
	std::cout << "Size of line =  " << line1.Size() << std::endl;            //проверка функции, возвращающей размер строки
	TString line2(line1);                                                            //вызывается конструктор копирования с параметром const TString& rhs
	if (line1 == line2) std::cout << "line1 and line2 are equal\n" << std::endl;       //проверка работы оператора ==
	TString line3 = "!!!!I'm string!!!!";
	std::cout << line3 << std::endl;
	line3.RTrim('!');                                                     //проверкаи работы функции RTrim
	std::cout << "After work RTrim('!') :  " << line3 << std::endl;
	line3.LTrim('!');                                                      //проверка работы функции LTrim
	std::cout << "After work LTrim('!') :  " << line3 << std::endl;
	TString line4;                                                      //вызывается конструктор без параметров 
	if (line1 > line3)  line4 = line1 + line3;                          //проверка операторов > и +
	std::cout << line4 << std::endl;
	line4.Replace('s', 'S');                                           //проверка работы функции Replace
	if (line4 != line2) std::cout << line4 << std::endl;               //проверка работы логического оператора !=
	if(line2.Find("w") == 6) std::cout << line3[2] << std::endl;             //проверка работы функции Find и оператора []
	line4 += "    Bye :)";                                                        //проверка операторa +=
	std::cout << line4 << std::endl;
	system("pause");
	return 0;
}





