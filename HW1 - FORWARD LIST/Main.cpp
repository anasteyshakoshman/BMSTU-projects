#include "TForwardList.h"


int main()
{
	TForwardList<int> list1(1, 199);
	std::cout << "List1(1, 199)\nlist 1 : " << list1 << std::endl;
	list1.push_back(1);
	std::cout << std::endl << "After push_back(1)\nlist 1 : " << list1 << std::endl;
	list1.push_front(87);
	std::cout << std::endl << "After push_front(87)\nlist 1 : " << list1 << std::endl;
	list1.resize(5, 23);
	std::cout << std::endl << "After resize(5, 23)\nlist 1 : " << list1 << std::endl;
	list1.pop_back();
	std::cout << std::endl << "After pop_back()\nlist 1 : " << list1 << std::endl;
	TForwardList<int> list2(list1);
	std::cout << std::endl << "List2(list1)\nlist 2 : " << list2 << std::endl;
	if (list1 == list2) list2.pop_front();
	std::cout << std::endl << "After pop_front()\nlist 2 : " << list2 << std::endl;
	list1.remove(199);
	std::cout << std::endl << "After remove(199)\nlist 1 : " << list1 << std::endl;
	list2.clear();
	for (size_t i = 0; i < list1.size(); ++i)
	{
		list2.push_back(i);
	}
	if (!list2.empty()) std::cout << std::endl << "After push_back(i), i = 0, 1, 2\nlist 2 : " << list2 << std::endl;
	list1.swap(list2);
	if (list2 >= list1) std::cout << std::endl << "After swap\nlist 1 : " << list1 << std::endl << "list 2 : " << list2 << std::endl;
	list1.assign(5, 16);
	std::cout << std::endl << "After assign(5, 16)\nlist 1 : " << list1 << std::endl;
	TForwardList<double> list3(2, 4.9);
	double k = 19.6;
	for (double i = 0.0; i < 10.0; ++i)
	{
		list3.push_front(i*k);
		k--;
	}
	std::cout << std::endl << "list 3 : " << list3 << std::endl;
	list3.sort();
	std::cout << std::endl << "After sort()\nlist 3 : " << list3 << std::endl;
	list2.assign(5, 5);
	list2.assign(10, 45);
	list2.push_back(87);
	std::cout << std::endl << "list 2 : " << list2 << std::endl;
	list2.unique();
	std::cout << std::endl << "After unique()\nlist 2 : " << list2 << std::endl;
	list2.reverse();
	std::cout << std::endl << "After reverse()\nlist 2 : " << list2 << std::endl;
	list2.insert_after(list2.begin(), 8);
	std::cout << std::endl << "After insert_after(list2.begin(), 8)\nlist 2 : " << list2 << std::endl;
	list2.erase_after(list2.begin());
	std::cout << std::endl << "After erase_after(list2.begin())\nlist 2 : " << list2 << std::endl;
	TForwardList<int>::TIterator it(list2.begin());
	it++; it++;
	list2.insert_after(it, 653);
	std::cout << std::endl << "After insert_after(it, 653), it = Head->Next->Next\nlist 2 : " << list2 << std::endl;
	list2.erase_after(it, list2.end());
	std::cout << std::endl << "After erase_after(it, list2.end())\nlist 2 : " << list2 << std::endl;
	TForwardList<int> list4(list2.begin(), list2.end());
	std::cout << "List4(list2.begin(), list2.end())\n" << list4 << std::endl;
	return 0;

};
