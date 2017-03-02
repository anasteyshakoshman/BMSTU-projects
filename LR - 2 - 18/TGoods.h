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
	float Cost(const float percent) const; //фун-ия, вычисляющая цену, по которой товар будет продаваться (в зависимости от процента прибыли)
	void Print() const;
	void SetName(const std::string name)const;  	
	void SetQuantity(const int quan) const;
	void SetPrice(float cost);
	int GetQuantity();
};
