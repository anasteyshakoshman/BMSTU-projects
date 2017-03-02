#include <iostream>
#include <string>


class TGoods
{
private:
	std::string Name;
	int Quantity;
	float Price;     //закупочная цена

public:
	TGoods();
	float Cost(float percent);   //фун-ия, вычисляющая цену, по которой товар будет продаваться (в зависимости от процента прибыли)
	void Print();
	void SetName(std::string name);
	void SetQuantity(int quan);
	void SetPrice(float cost);
	int GetQuantity();
};
