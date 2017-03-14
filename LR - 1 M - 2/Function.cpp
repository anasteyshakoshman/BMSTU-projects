#include "Header.h"

int intFromString(const char * data)
{
	bool minus = false;
	int ind = 0;
	double number = 0.0;
	double tmp = 0.0;
	if (data[0] == '+' || data[0] == '-')
	{
		ind++;
		if (data[0] == '-') minus++;
	}
	while (data[ind])
	{
		if (data[ind] >= 48 && data[ind] <= 57)
		{
			tmp = data[ind] - 48;
			number = number * 10 + tmp;
			ind++;
		}
		else if (data[ind] == ' ') ind++;
		else throw TUnknown("This line is unknown!!");
	}
	if (minus == true) number *= (-1);
	if (number > INT_MAX) throw TMax("Maximum limit of int was be  exceeded !!");
	if (number < INT_MIN) throw TMin("Minimum limit of int was be  exceeded !!");
	int Number = (int)number;
	return Number;
}

bool boolFromString(const char * data)
{
	if (!strcmp(data, "0") || !strcmp(data, "false") || !strcmp(data, "FALSE") || !strcmp(data, "False"))
	{
		return 0;
	}
	if (!strcmp(data, "1") || !strcmp(data, "true") || !strcmp(data, "TRUE") || !strcmp(data, "True"))
	{
		return 1;
	}
	else throw TUnknown("This line is unknown!!");
}

float floatFromString(const char * data)
{
	bool minus = false;
	bool znak = false;
	bool point = false;
	int ind = 0;
	double number = 0.0;
	double tmp = 0;
	int st = -1;       //степень, в которую возводим 10 после точки
	if (data[0] == '+' || data[0] == '-')
	{
		ind++;
		znak = true;
		if (data[0] == '-') minus = true;
	}
	while (data[ind])
	{
		if (data[ind] >= 48 && data[ind] <= 57 )
		{
			if (point == false)
			{
				tmp = data[ind] - 48;
				number = number * 10 + tmp;
				ind++;
			}
			else
			{
				tmp = data[ind] - 48;
				number += tmp * pow(10, st);
				ind++;
				st--;
			}			
		}
		else if (data[ind] == '.' || data[ind] == ',')    
		{ 
			if (ind == 0)                        //точка не может стоять на 0 позиции
			{
				throw TUnknown("This line is unknown!!");
			}
			else if (ind == 1 && znak == true)     //точка не может стоять на 1 позиции, если есть знак
			{
				throw TUnknown("This line is unknown!!");
			}
			else
			{
				point = true;
				ind++;
			}
		}
		else if (data[ind] == ' ') ind++;
		else throw TUnknown("This line is unknown!!");
	}
	if (minus == true) number *= (-1);
	if (number > 2147483648.0) throw TMax("Maximum limit of float was be  exceeded !!");
	if (number < -2147483648.0) throw TMin("Minimum limit of float was be  exceeded !!");
	float Number = (float)number;
	return Number;
	
}
