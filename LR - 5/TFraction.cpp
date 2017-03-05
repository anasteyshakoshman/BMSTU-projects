#include "TFraction.h"


TFraction::TFraction(void) : TPair()   //конструктор без параметров (вызывается кон-ор базового класса TPair) 
{}

TFraction::TFraction(int first, int second) : TPair(first, second)   //конструктор c параметрами (вызывается кон-ор базового класса TPair) 
{}


	//переопределенные методы сранения полей :

bool TFraction::operator >(const TFraction & b)
{
	float c = (float)First / (float)Second;
	float d = (float)b.First / (float)b.Second;
	if (c > d) return 1;
	else return 0;
}

bool TFraction::operator <(const TFraction & b)
{
	float c = (float)First / (float)Second;
	float d = (float)b.First / (float)b.Second;
	if (c < d) return 1;
	else return 0;
}


 


