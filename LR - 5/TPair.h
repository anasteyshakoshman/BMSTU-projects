#pragma once
#include <iostream>



class TPair
{

protected:

	int First;
	int Second;
	
public:

	TPair(void);   //конструктор без параметров


	TPair(int, int);   //конструктор с параметрами
	
	virtual ~TPair()=default;   //деструктор
	
	TPair(const TPair &);   //конструктор копирования

	TPair & operator=(const TPair &);         //операция присваивания 


	//модификаторы :
	
	void SetFirst(const int);

	void SetSecond(const int);


	//методы сравнения полей :

	bool operator ==(const TPair & b);

	bool operator !=(const TPair & b);
		

	//виртуальные методы сравнения полей:

	virtual bool operator >(const TPair & b);

	virtual bool operator <(const TPair & b);

	

	//глобальные операторы-функции ввода-вывода :
	
	friend std::istream & operator>>(std::istream & in, TPair & p);
	
	friend std::ostream & operator<<(std::ostream & out, TPair & p);
};


