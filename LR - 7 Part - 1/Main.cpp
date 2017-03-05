#include <iostream>
#include <string>

bool checkPalindrome(const std::string & l) 
{
	int len = l.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (l[i] != l[len - i - 1])
		{
			return false;
		}
	}
}


int main()
{
	std::string line;
	std::cout << "Let's start!\nIf you will want to exit, enter EXIT" << std::endl;
	while (line != "EXIT")
	{
		std::cout << std::endl << "Enter the line: " << std::endl;
		getline(std::cin, line);
		if (line != "EXIT")
		{
			if (checkPalindrome(line)) std::cout << "This line is palindrome" << std::endl;
			else std::cout << "This line isn't palindrome" << std::endl;
		}		
	}
	system("pause");
	return 0;
}


