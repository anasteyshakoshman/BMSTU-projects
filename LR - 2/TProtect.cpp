#include "TProtect.h"


TProtect::TProtect()
{
}


TProtect::~TProtect()
{
}


void TProtect::SetName(const std::string nm)
{
	Name = nm;
}


void TProtect::SetType(const int ch)
{
	Type = ch;
}

bool TProtect::GetType()
{
	return Type;
}



void TProtect::print()
{
	std::cout <<"Name : " << Name << std::endl;
	if (Type == 1) std::cout << "Type : Symmetric" << std::endl << std::endl;
	if (Type == 0) std::cout << "Type : Asymmetric" << std::endl << std::endl;
}



