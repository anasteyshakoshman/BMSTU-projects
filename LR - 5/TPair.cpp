#include "TPair.h"


TPair::TPair(void)   //конструктор без параметров
{
	First = 0;
	Second = 0;
}



TPair::TPair(int a, int b)   //конструктор с параметрами
{
	First = a;
	Second = b;
}


TPair::TPair(const TPair & p)   //конструктор копирования
{
	First = p.First;
	Second = p.Second;
}


TPair & TPair::operator = (const TPair & p)      //операция присваивания 
{
	if (&p == this) return *this;
	First = p.First;
	Second = p.Second;
	return *this;
}

//модификаторы :

void TPair::SetFirst(const int first) 
{
	First = first;
}

void TPair::SetSecond(const int second)
{
	Second = second;
}



//виртуальные методы сравнения полей:

bool TPair::operator >(const TPair & b)
{
	if ((First > b.First) || (First == b.First && Second > b.Second)) return 1;
	else return 0;
}

bool TPair::operator <(const TPair & b)
{
	if ((First < b.First) || (First == b.First && Second < b.Second)) return 1;
	else return 0;
}

	//методы сравнения полей :
bool TPair::operator ==(const TPair & b)
{
	if (First == b.First && Second == b.Second) return 1;
	else return 0;
}

bool TPair::operator !=(const TPair & b)
{
	if (First != b.First && Second != b.Second) return 1;
	else return 0;
}

//глобальные операторы-функции ввода-вывода :

std::istream& operator>>(std::istream & in, TPair & p)
{
	std::cout << "\nFirst : ";
	in >> p.First;
	std::cout << "\nSecond : ";
	in >> p.Second;
	return in;
}


std::ostream & operator<<(std::ostream & out, TPair & p)
{
	out << "\nFirst : " << p.First << "\nSecond : " << p.Second << std::endl;
	return out;
}


