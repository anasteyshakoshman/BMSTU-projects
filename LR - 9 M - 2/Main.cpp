#include "TScoredPtr.h"
#include <iostream>



int main()
{
	int * arr1 = new int[2];
	arr1[0] = 16;
	arr1[1] = 34;
	TScopedPtr<int> pS1(arr1);
	if (pS1) std::cout << "pS1 : " << *pS1 << std::endl;

	float * arr2 = new float[1];
	arr2[0] = 16.5678;
	TScopedPtr<float> pS2(arr2);
	if (pS2) std::cout << "pS2 : " << *pS2 << std::endl;

	float * arr3 = new float[1];
	arr3[0] = 5678.876;
	pS2.reset(arr3);
	std::cout << "pS2 : " << *pS2 << std::endl;

	TScopedPtr<int> pS4(arr1 + 1);
	std::cout << "pS4 : " << *pS4 << std::endl;
	swap(pS1, pS4);
	std::cout << "After swap(pS1, pS4)" << std::endl << "pS1 : " << *pS1 << std::endl << "pS4 : " << *pS4 << std::endl;

	system("pause");
	return 0;

}
