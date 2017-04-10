#include <iostream>
#include <vector>
#include <list>
#include <iterator>



template <typename T>

void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class IT>

void sort(IT beg, IT end)
{
	for (IT i = beg; i != end; ++i)
	{
		for (IT k = ++beg; k != end; ++k)
		{
			if (*i > *k) swap(*i, *k);
		}
	}
}


int main()
{
	int arr[] = { 123, 3, 0, 13212, -100 };
	sort(arr + 0, arr + 3); // arr: 0, 3, 123, 13212, -100
	for (int i = 0; i < 5; ++i)
	{
		std::cout << arr[i] << " ";
	}
	sort(arr + 2, arr + 5); // arr: 0, 3, -100, 123, 13212
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::vector <double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	sort(vec.begin(), vec.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	for (int i = 0; i < 5; ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	std::list<int> M {3, 34, 7, 5};
	sort(M.begin(), M.end());
	std::copy(M.begin(), M.end(), std::ostream_iterator<int>(std::cout, " "));  

	return 0;
}








