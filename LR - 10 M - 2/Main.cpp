#include "TArray.h"



void main()
{
	TArray<int, 10> mus1 { 5, 9, 78, 23, 98, 16, 65, 54, 90, 100 };
	if(mus1.size() == 10) std::cout << "mus1 : " << mus1;
	TArray<int, 10> mus2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	if (mus1 >= mus2) 	std::cout << "mus2 : " << mus2;
	TArray<char, 2> mus3 { 'h', 'i' };
	TArray<char, 2> mus4{ 'h', 'i' };
	if (mus3 == mus4) std::cout << "mus3 : " << mus3;
	if (!mus4.empty()) std::cout << "mus4 : " << mus4;
	mus1.swap(mus2);
	std::cout << "After mus1.swap(mus2) \nmus1 : " << mus1 << "mus2 : " << mus2;
	TArray<double, 1> mus5;
	mus5.fill(156.876);
	std::cout << "mus5 : " << mus5;
	system("pause");

}
