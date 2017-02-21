#include "TStudent.h"

int main()
{
	int n = 0;
	TStudent *pS;
	pS = new TStudent[n];
	std::string fio;
	int ocenki[4];
	std::cout << "Enter quantity of students:  ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << "FIO: ";
		_flushall();
		getline(std::cin, fio);
		std::cout << std::endl << "Enter four score of student : " << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << "Score: ";
			_flushall();
			std::cin >> ocenki[j];
			pS[i].SetOcenki(ocenki[j], j);
		}
		pS[i].SetFio(fio);
	}
	for (int i = 0; i < n; i++)
	{
		if (pS[i].Stipendia())
			pS[i].print();
	}
	delete[] pS;
	system("pause");
	return 0;
}
