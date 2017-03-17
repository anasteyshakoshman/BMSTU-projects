#include "TInteger.h"
#include "Exception.h"
#include "Limits.h"


bool TInteger::Error(const long long int a)
{
	if (a > INT_MAX) throw TMax("Maximum limit of int was be exceeded!!");
	if (a < INT_MIN) throw TMin("Minimum limit of int was be exceeded!!");
	return true;
}


TInteger::TInteger()
{
	Num = 0;
}

TInteger::TInteger(const int number)
{
	Num = number;
}

TInteger::TInteger(const long long int number)
{
	Error(number);
	Num = number;
}


TInteger& TInteger::operator =(const long long int number)
{
	Error(number);
	Num = number;
	return *this;
}

TInteger& TInteger::operator +=(const long long int number)
{
	Error(number);
	int long long rez = Num + number;
	Error(rez);
	Num = rez;
	return *this;
}

TInteger& TInteger::operator *=(const long long int number)
{
	Error(number);
	long long int rez = Num * number;
	Error(rez);
	Num = rez;
	return *this;
}

TInteger& TInteger::operator %=(const long long int number)
{
	Error(number);
	Num = Num % number;         //äåëàòü ïðîâåðêó íå íàäî, ò.ê. ïðè äåëåíèè ïî ìîäóëþ ðåçóëüòàò 
	return *this;                //íå ìîæåò ïîëó÷èòñÿ áîëüøå ÷åì èñõîäíîå çíà÷åíèå
}

TInteger& TInteger::operator /= (const long long int number)
{
	Error(number);
	Num = Num / number;     //äåëàòü ïðîâåðêó íå íàäî, ò.ê. ïðè äåëåíèè ðåçóëüòàò
	return *this;           //íå ìîæåò ïîëó÷èòñÿ áîëüøå ÷åì èñõîäíîå çíà÷åíèå
}


TInteger& TInteger::operator -=(const long long int number)
{
	int long long rez = Num - number;
	Error(rez);
	Num = rez;
	return *this;
}



bool TInteger::operator ==(const int number) const
{
	return  ((this->Num == number) ? true : false);
}


bool TInteger::operator <(const int number) const
{
	return ((this->Num < number) ? true : false);
}




TInteger& TInteger::operator++()
{
	Num++;
	return *this;
}


TInteger& TInteger::operator--()
{
	Num--;
	return *this;
}



TInteger::TInteger(const TInteger& el)
{
	Num = el.Num;
}


TInteger& TInteger::operator =(const TInteger& el)
{
	if (&el == this) return *this;
	Num = el.Num;
	return *this;
}


TInteger& TInteger::operator +=(const TInteger& el)
{
	int long long rez = Num + el.Num;
	Error(rez);
	Num = rez;
	return *this;
}

TInteger& TInteger::operator *= (const TInteger& el)
{
	long long int rez = Num * el.Num;
	Error(rez);
	Num = rez;
	return *this;
}

TInteger& TInteger::operator %=(const TInteger& el)
{
	Num = Num % el.Num;          //äåëàòü ïðîâåðêó íå íàäî, ò.ê. ïðè äåëåíèè ïî ìîäóëþ ðåçóëüòàò 
	return *this;                //íå ìîæåò ïîëó÷èòñÿ áîëüøå ÷åì èñõîäíîå çíà÷åíèå
}



TInteger& TInteger::operator /= (const TInteger& el)
{
	Num = Num / el.Num;     //äåëàòü ïðîâåðêó íå íàäî, ò.ê. ïðè äåëåíèè ðåçóëüòàò
	return *this;           //íå ìîæåò ïîëó÷èòñÿ áîëüøå ÷åì èñõîäíîå çíà÷åíèå
}


TInteger& TInteger::operator -=(const TInteger& el)
{
	int long long rez = Num - el.Num;
	Error(rez);
	Num = rez;
	return *this;
}

bool TInteger::operator ==(const TInteger& el) const
{
	return ((this->Num != el.Num) ? false : true);
}


bool TInteger::operator <(const TInteger& el) const
{
	return ((this->Num < el.Num) ? true : false);
}








TInteger operator %(const TInteger& first, const long long int number)
{
	TInteger rez = first;
	rez %= number;
	return rez;
}


TInteger operator /(const TInteger& first, const long long int number)
{
	TInteger rez = first;
	rez /= number;
	return rez;
}


TInteger operator *(const TInteger& first, const long long int number)
{
	TInteger rez = first;
	rez *= number;             //ïðîâåðêà ñäåëàíà â îïåðàòîðå *=
	return rez;
}


TInteger operator +(const TInteger& first, const long long int number)
{
	TInteger summa = first;
	summa += number;          //ïðîâåðêà ñäåëàíà â îïåðàòîðå +=
	return summa;
}


TInteger operator -(const TInteger& first, const long long int number)
{
	TInteger summa = first;
	summa -= number;          //ïðîâåðêà ñäåëàíà â îïåðàòîðå -=
	return summa;
}


bool operator !=(const TInteger& first, const long long int number)
{
	return ((first == number) ? false : true);
}


bool operator >(const TInteger& first, const long long int number)
{
	return (((first < number) || (first == number)) ? false : true);
}


TInteger operator %(const long long int number, const TInteger& second)
{
	TInteger rez = number;
	rez %= second;
	return rez;
}


TInteger operator /(const long long int number, const TInteger& second)
{
	TInteger rez = number;
	rez /= second;
	return rez;
}


TInteger operator *(const long long int number, const TInteger& second)
{
	TInteger rez = number;
	rez *= second;          //ïðîâåðêà ñäåëàíà â îïåðàòîðå *=
	return rez;
}


TInteger operator +(const long long int  number, const TInteger& second)
{
	TInteger summa = number;    //ïðîâåðêà ñäåëàíà â îïåðàòîðå =
	summa += second;            //ïðîâåðêà ñäåëàíà â îïåðàòîðå +=
	return summa;
}

TInteger operator -(const long long int number, const TInteger& second)
{
	TInteger summa = number;      //ïðîâåðêà ñäåëàíà â îïåðàòîðå =
	summa -= second;            //ïðîâåðêà ñäåëàíà â îïåðàòîðå -=
	return summa;
}


bool operator !=(const int number, const TInteger& second)
{
	return ((second == number) ? false : true);
}
 

bool operator >(const long long int number, const TInteger& second)
{
	return ((second < number)  ? true : false);
}





TInteger operator %(const TInteger& first, const TInteger& second)
{
	TInteger rez = first;
	rez %= second;
	return rez;
}



TInteger operator /(const TInteger& first, const TInteger& second)
{
	TInteger rez = first;
	rez /= second;
	return rez;
}


TInteger operator *(const TInteger& first, const TInteger& second)
{
	TInteger rez = first;
	rez *= second;          //ïðîâåðêà ñäåëàíà â îïåðàòîðå *=
	return rez;
}


TInteger operator +(const TInteg