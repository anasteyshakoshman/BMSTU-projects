#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector <int> Research(const std::vector <std::string> & text, const std::string & word)
{
	std::vector <int> number;
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == word)
		{
			number.push_back(i);
		}
	}
	return number;
}


std::vector <std::string> newVector(const std::string & line)
{
	std::vector <std::string> newLine;
	std::string word;
	for (int i = 0; i < line.length(); i++)
	{  
		if (isalpha(line[i]) != 0)             //isalpha проверяет аргумент,  является ли он строчной или прописной буквой алфавита.
		{
			word.push_back(char(tolower(line[i])));
		}
		else if (word.empty() == 0)
		{
			newLine.push_back(word);
			word = "";
		}
	}
	return newLine;
}



void Print(const std::vector <std::string> & text, const int index, const int quan, const std::string & word)
{
	int k = 0, i = 0;
	if (index != text.size() - 1)
	{
		i = index + 1;

		std::cout << "The right  of " << word << " : ";
		while (true)
		{
			if (i == text.size() || k == quan) break;
			std::cout << text[i] << " ";
			k++;
			i++;
		}
		std::cout << std::endl;
	}
	if (index != 0)
	{
		i = index - 1;
		std::string left;
		std::cout << "The left  of " << word << " : ";
		while (true)
		{
			if (i < 0 || k == quan) break;
			left = text[i] + " " + left;
			k++;
			i--;
		}
		std::cout << left << std::endl;
	}
}

void Change(std::string & word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = char(tolower(word[i]));     //tolower выполняет преобразование прописных букв в строчные
	}
}

void main()
{
	std::string way;
	std::cout << "Enter the way to the file : ";
	getline(std::cin, way);
	std::cout << std::endl;
	std::fstream pFile(way);   // fstream - это класс для работы с файлами
	std::string word;
	std::cout << "Enter the word :";
	getline(std::cin, word);
	std::cout << std::endl;
	Change(word);
	int quan = 0;
	std::cout << "Enter the quantity of words in the left and in the right";
	std::cin >> quan;
	std::cout << std::endl;
	std::string line;
	int step = 1;
	bool check = 0;
	while (getline(pFile, line))
	{
		std::vector <std::string> text = newVector(line);

		std::vector <int> number = Research(text, word);
		 
		if (number.empty() == 0)
		{
			check = 1;
			for (int i = 0; i < number.size(); i++)
			{
				std::cout << "In string = " << step << " ";
				Print(text, number[i], quan, word);
			}
		}
		else
		{
			step++;
			continue;
		}
		step++;
	}
	if (check == 0)
	{
		std::cout << "This file haven't this word" << std::endl;
	}
	pFile.close();     // для закрытия файла используется метод close (аналог fclose для FILE *)
	system("pause");
}
