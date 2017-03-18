#pragma once
#include <iostream>

class TInteger
{
	int Num;
	bool Error(const long long int);


public:   
	TInteger();

	TInteger(const int);      
	TInteger(const long long int);      
	TInteger& operator =(const long long int);     
	TInteger& operator +=(const long long int);     
	TInteger& operator *=(const long long int);     
	TInteger& operator %=(const long long int);      
	TInteger& operator /=(const long long int);
	TInteger& operator -=(const long long int);
	bool operator ==(const int) const;
	bool operator <(const int) const;

	TInteger& operator ++();
	TInteger& operator--();
	TInteger(const TInteger&);             
	TInteger& operator =(const TInteger&);
	TInteger& operator +=(const TInteger&);
	TInteger& operator *=(const TInteger&);
	TInteger& operator %=(const TInteger&);
	TInteger& operator /=(const TInteger&);
	TInteger& operator -=(const TInteger&);
	bool operator ==(const TInteger&) const;
	bool operator <(const TInteger&) const;


	operator int();
	TInteger& operator =(const int);
	TInteger& operator +=(const int);
	TInteger& operator *=(const int);
	TInteger& operator %=(const int);
	TInteger& operator /=(const int);
	TInteger& operator -=(const int);

	friend std::ostream & operator<<(std::ostream & out, const TInteger &);
};

TInteger operator %(const TInteger&, const long long int);
TInteger operator /(const TInteger&, const long long int);
TInteger operator *(const TInteger&, const long long int);
TInteger operator +(const TInteger&, const long long int);
TInteger operator -(const TInteger&, const long long int);
bool operator !=(const TInteger&, const int);
bool operator >(const TInteger&, const  int);

TInteger operator %(const long long int, const TInteger&);
TInteger operator /(const long long int, const TInteger&);
TInteger operator *(const long long int, const TInteger&);
TInteger operator +(const long long int, const TInteger&);
TInteger operator -(const long long int, const TInteger&);
bool operator !=(const int, const TInteger&);
bool operator >(const int, const TInteger&);

TInteger operator %(const TInteger&, const TInteger&);   
TInteger operator /(const TInteger&, const TInteger&);
TInteger operator *(const TInteger&, const TInteger&);
TInteger operator +(const TInteger&, const TInteger&);
TInteger operator -(const TInteger&, const TInteger&);
bool operator !=(const TInteger&, const TInteger&);
bool operator >(const TInteger&, const TInteger&);

TInteger operator %(const TInteger&, const int);
TInteger operator /(const TInteger&, const int);
TInteger operator *(const TInteger&, const int);
TInteger operator +(const TInteger&, const int);
TInteger operator -(const TInteger&, const int);





