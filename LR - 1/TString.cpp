#include "TString.h"





TString::TString()
{
	Data = new char[1];
	Data[0] = '\0';
}


TString::~TString()
{
	delete[] Data;
}



TString::TString(const TString& rhs)
{
	size_t count = rhs.Size();
	Data = new char[count + 1 ];
	for (int i = 0; i < count; i++)
	{
		Data[i] = rhs.Data[i];
	}
	Data[count] = '\0';
}


TString::TString(const char * data)
{
	size_t count = 0;
	while (data[count] != '\0') count++;
	Data = new char[count + 1];
	for (int i = 0; i < count; i++)  Data[i] = data[i];
	Data[count] = '\0';
}



TString& TString::operator =(const TString& rhs)
{
	if (&rhs == this) return *this;
	if (Data != nullptr) delete[] Data;
	Data = new char[rhs.Size() + 1];
	for (int i = 0; i < rhs.Size(); i++) Data[i] = rhs.Data[i];
	Data[rhs.Size()] = '\0';
	return *this;
}



TString& TString::operator +=(const TString& rhs)
{
	size_t count_1 = Size(), count_2 = rhs.Size();
	size_t count = count_1 + count_2;
	char * New = new char[count + 1];
	for (int i = 0; i < count_1; i++) New[i] = Data[i];
	for (int i = 0; i < count_2; i++) New[count_1 + i] = rhs.Data[i];
	New[count] = '\0';
	delete[] Data;
	Data = New;
	return *this;	 
}



bool TString::operator ==(const TString& rhs) const
{ 
	if (Size() != rhs.Size()) return false;
	for (int i = 0; i < Size(); i++)
	{
		if (Data[i] != rhs.Data[i]) return false;
	}
	return true;	
}

bool TString::operator <(const TString& rhs) const
{
	for (int i = 0; i < Size() && i < rhs.Size(); i++)
	{
		if (Data[i] < rhs.Data[i]) return true;
		if (Data[i] > rhs.Data[i]) return false;
	}
	return false;
}

size_t TString::Find(const TString& substr) const
{
	for (int i = 0; i < Size(); i++) 
	{
		for (int j = 0; j < substr.Size(); j++)
		{
			if (Data[i + j] != substr.Data[j]) break;
			if (j == substr.Size() - 1) return i;
		}
	}
	return -1;
}

void TString::Replace(char oldSymbol, char newSymbol)
{
	for (int i = 0; i < Size(); i++)
	{
		if (Data[i] == oldSymbol) Data[i] = newSymbol;
	}
}



size_t TString::Size() const
{
	int len = 0;
	while (Data[len] != '\0') len++;
	return len;
}

bool TString::Empty() const
{
	if (Size()) return 0;
	return 1;
}

char TString::operator[](size_t index) const
{
	return Data[index];
}

char& TString:: operator[](size_t index)
{
	return Data[index];
}

void TString::RTrim(char symbol)
{
	int i = 0, count = Size();
	while (Data[count - i - 1] == symbol) i++;
	if (!i) return;
	char * New =  new char[count  - i + 1];
	for (int j = 0; j < count - i; j++)
	{
		New[j] = Data[j];
	}
	New[count - i] = '\0';
	delete[] Data;
	Data = New;
}

void TString::LTrim(char symbol)
{
	int i = 0, count = Size();
	while (Data[i] == symbol) i++;
	if (!i) return;
	char * New = new char[count - i + 1];
	for (int j = 0; j < count - i; j++)
	{
		New[j] = Data[j + i];
	}
	New[count - i] = '\0';
	delete[] Data;
	Data = New;
}



TString operator +(const TString & a, const TString & b)
{    
	TString summa = a;
	summa += b;
	return summa;
}

bool operator!=(const TString & a, const TString & b)
{
	return ((a == b) ? 0 : 1);
}

bool operator>(const TString & a, const TString & b)
{
	if ((a == b) && (a < b)) return 0;
	else                     return 1;
}


std::ostream & operator<<(std::ostream &out, const TString &str)
{
	out << str.Data;
	return out;
}
