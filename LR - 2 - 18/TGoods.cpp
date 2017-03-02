#include "TGoods.h"


TGoods::TGoods()
{
	Name = " ";
	Quantity = 0;
	Price = 0.0;
}

float TGoods::Cost(float percent)
{
	float cost = (Price * percent) / 100;   //на сколько цена увеличится
	cost += Price;    //закупочная цена + на сколько цена увеличится
	return cost;
}


void TGoods::Print()
{
	std::cout << "\nName : " << Name << std::endl;
	std::cout << "\nQuantity : " << Quantity << std::endl;
	std::cout << "\nPrice : " << Price << std::endl;
}


void TGoods::SetName(std::string name)
{
	Name = name;
}

void TGoods::SetQuantity(int quan)
{
	Quantity = quan;
}

void TGoods::SetPrice(float price)
{
	Price = price;
}
int TGoods::GetQuantity()
{
	return Quantity;
}



