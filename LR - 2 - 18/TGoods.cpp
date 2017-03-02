#include "TGoods.h"


TGoods::TGoods()
{
	Name = " ";
	Quantity = 0;
	Price = 0.0;
}

float TGoods::Cost(const float percent) const
{
	float cost = (Price * percent) / 100;   //на сколько цена увеличится
	cost += Price;    //закупочная цена + на сколько цена увеличится
	return cost;
}


void TGoods::Print() const 
{
	std::cout << "\nName : " << Name << std::endl;
	std::cout << "\nQuantity : " << Quantity << std::endl;
	std::cout << "\nPrice : " << Price << std::endl;
}


void TGoods::SetName(const std::string name) const
{
	Name = name;
}

void TGoods::SetQuantity(const int quan) const
{
	Quantity = quan;
}

void TGoods::SetPrice(const float price) const
{
	Price = price;
}
int TGoods::GetQuantity() const
{
	return Quantity;
}



