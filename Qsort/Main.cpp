#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

//Реализуйте шаблонный алгоритм "быстрой сортировки":
//template<class It, class Cmp>
//void qsort(It beg, It end, Cmp cmp);


template<class It, class Cmp>

void qsort(It first, It last, Cmp & cmp)
{
	if (first != last)
	{
		It left = first;
		It right = last;
		It tmp = left++;
		while (left != right)
		{
			if (cmp(*left, *tmp))
			{
				++left;
			}
			else
			{
				while ((left != --right) && cmp(*tmp, *right));
				{
					std::iter_swap(left, right);
				}
			}
		}
		--left;
		std::iter_swap(first, left);
		qsort(first, left, cmp);
		qsort(right, last, cmp);
	}
	else throw std::logic_error("Uncorrect values of iterators");
}


int main()
{
	std::vector<int> vec = { 7, 2, 9, 45, 67, 23, 99, 1000, 1999, 4, 2, 8, 5 };
	size_t i = 0;
	while (i < vec.size())
	{
		std::cout << vec[i] << " ";
		++i;
	}
	qsort(vec.begin(), vec.end(), std::less<int> { } );
	i = 0;
	std::cout << "After sort : " << std::endl;
	while (i < vec.size())
	{
		std::cout << vec[i] << " ";
		++i;
	}
	system("pause");
	return 0;
}


