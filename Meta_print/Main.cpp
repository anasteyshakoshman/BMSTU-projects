
#include <iostream>

template <size_t N, size_t MAX>

struct print
{		
	print()
	{
		std::cout << N << std::endl;
		print <N + 1, MAX> ();
	}
};

template <size_t MAX> 

struct print < MAX, MAX > 
{ };


int main()
{
	print < 0, 101 > array;
}
