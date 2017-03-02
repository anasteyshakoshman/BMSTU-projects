#include "TProtect.h"


TProtect::TProtect()
{
	Name = " ";
	Type = 0;
}

void TProtect::SetName(const std::string nm)
{
	Name = nm;
}


void TProtect::SetType(const int ch)
{
	Type = ch;
}

bool TProtect::GetType() const
{
	return Type;
}



void TProtect::print() const
{
	std::cout <<"Name : " << Name << std::endl;
	if (Type == true) std::cout << "Type : Symmetric" << std::endl << std::endl;
	if (Type == false) std::cout << "Type : Asymmetric" << std::endl << std::endl;
}



