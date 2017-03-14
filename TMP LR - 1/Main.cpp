#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <locale>


struct List
{  
	std::string Data;
	std::vector<int> NumLine;
	std::vector<int> NumFile;	
	List * next;
};



struct List * New(std::string data, int first, int number)
{
	List *lst = new List;
	lst->Data = data;
	lst->NumFile.push_back(first);
	lst->NumLine.push_back(number);
	lst->next = NULL;
	return(lst);
}

typedef List * pL;

pL Find(pL p, std::string data)
{
	pL tmp = p;
	while (tmp)
	{
		if (tmp->Data == data)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void Print(pL p)
{
	pL tmp = p;
	while (tmp)
	{
		if (tmp->NumFile.size() != 2)
		{
			std::cout << "FILE number" << tmp->NumFile[0] << "\nline" << tmp->NumLine[0] << "\n" << tmp->Data << std::endl;
		}
		tmp = tmp->next;
	}
}

struct List * Add(List *lst, std::string data, int first, int number)
{
	List *tmp = new List;
	List *pl = lst->next;
	lst->next = tmp;
	tmp->Data = data;
	tmp->NumFile.push_back(first);
	tmp->NumLine.push_back(number);
	tmp->next = pl;
	return(lst);
}


void main()
{
	setlocale(LC_ALL, "rus");
	std::string way_1, way_2;
	std::cout << "Введите путь к первому файлу" << std::endl;
	getline(std::cin, way_1);
	std::cout << "Введите путь к второму файлу" << std::endl;
	getline(std::cin, way_2);
	std::ifstream pF_1(way_1);
	std::ifstream pF_2(way_2);
	pL pF;
	std::string text;
	int numFile = 1;
	int numLine = 1;
	int ch = 1;
	while (getline(pF_1, text))
	{
		if (ch)
		{
			pF = New(text, numFile, numLine);
			ch--;
		}
		else
		{
			pF = Add(pF, text, numFile, numLine);
		}
		numLine++;
	}
	numFile = 2;
	numLine = 1;
	while (getline(pF_2, text))
	{
		pL h = Find(pF, text);
		if (h == 0)
		{
			pF = Add(pF, text, numFile, numLine);
		}
		else 
		{
			h->NumLine.push_back(numLine);
			h->NumFile.push_back(numFile);
		}
	}
	Print(pF);
	pF_1.close();
	pF_2.close();
	system("pause");
}
