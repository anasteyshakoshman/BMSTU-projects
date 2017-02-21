#include "TStudent.h"


TStudent::TStudent()
{	
}


TStudent::~TStudent()
{
}


bool TStudent::Stipendia()
{
	for (int i = 0; i < 4; i++)
	{
		if (Ocenki[i] < 4) return 0;
	}
	return 1;
}


void TStudent::SetFio(const std::string fio)
{
	this->FIO = fio;
}

void TStudent::SetOcenki(const int oc, const int i)
{
	Ocenki[i] = oc;
}

void TStudent::print()
{
	std::cout << FIO << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Ocenki[i] << std::endl;
	}	
}
