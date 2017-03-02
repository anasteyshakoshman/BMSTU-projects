#include "TGoods.h"



int main()
{
	int n = 0;
	std::cout << "Enter guantity of products : ";
	std::cin >> n;
	std::cout << std::endl;
	TGoods * pG = new TGoods[n];
	std::string name;
	int quan = 0;
	float price = 0.0;
	for (int i = 0; i < n; i++)
	{
		std::cout << "\nEnter name of product : ";
		_flushall();
		getline(std::cin, name);
		pG[i].SetName(name);
		std::cout << "\nEnter quantity of products : ";
		std::cin >> quan;
		pG[i].SetQuantity(quan);
		std::cout << "\nEnter price of product : ";
		std::cin >> price;
		pG[i].SetPrice(price);
	}
	float procent = 0;
	std::cout << "\nEnter procent : ";
	std::cin >> procent;
	float allCost = 0;    //общая цена всех товаров
	for (int i = 0; i < n; i++)
	{
		pG[i].Print();
		allCost += pG[i].Cost(procent) * (float)pG[i].GetQuantity();
	}
	std::cout << "\nPrice of all products is : " << allCost << std::endl;
	delete[] pG;

	system("pause");
	return 0;
}
