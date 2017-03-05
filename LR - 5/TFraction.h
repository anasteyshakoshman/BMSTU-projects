#pragma once
#include "TPair.h"



class TFraction : public TPair   //наследуется от класса TPair
{ 

public:

	TFraction(void);  //конструктор без параметров

	TFraction::TFraction(int first, int second);  //конструктор c параметрами (вызывается кон-ор базового класса TPair) 

	
	//переопределенные методы сравнения полей:

	virtual bool operator >(const TFraction & b);

	virtual bool operator <(const TFraction & b);

};





