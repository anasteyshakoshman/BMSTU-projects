 #pragma once
#include <iostream>
#include <string>


class TProtect
{
	std::string Name;
	bool Type;  // 1- симметричный, 0 - несимметричный

public:
	TProtect();
	void SetName(const std::string nm);
	void SetType(const int ch);
	bool GetType() const;
	void print() const;
};

