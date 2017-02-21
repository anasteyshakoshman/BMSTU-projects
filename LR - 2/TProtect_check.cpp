#include "TProtect.h"

int main()
{
	int n = 0;
	bool check;
	std::string name;
	std::cout << "Enter quantity of elements:  ";
	std::cin >> n;
	TProtect *pS = new TProtect[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << std::endl << "Enter name of protect: ";
		_flushall();
		getline(std::cin, name);
		std::cout << std::endl << "Enter type of protect (0 - if type is asymmetric, 1 - if type is symmetric) : ";
		std::cin >> check;
		pS[i].SetType(check);
		pS[i].SetName(name);
	}
	std::cout << std::endl << "What type of elements will you want to see? Enter 0 - if type is asymmetric, 1 - if type is symmetric) : ";
	std::cin >> check;
	if (check == true) std::cout <<std::endl << std::endl << "You chose symmetric type: " << std::endl << std::endl;
	if (check == false) std::cout << "You chose asymmetric type: " << std::endl << std::endl;
	for (int i = 0; i < n; i++)
	{
		if (pS[i].GetType() == check) pS[i].print();
	}
	delete[] pS;
	system("pause");
	return 0;
}
