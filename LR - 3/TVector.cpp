#include "TVector.h"


TVector::TVector()
{
	Data = nullptr;
	Len = 0;
}


TVector::~TVector()
{
	delete [] Data;
}



TVector::TVector(const double * const mus, const size_t count)
{
	Len = count;
	Data = new double[Len];
	for (int i = 0; i < Len; i++) Data[i] = mus[i];
}


TVector::TVector(const TVector& vec)
{
	Len = vec.Len;
	Data = new double[Len];
	for (int i = 0; i < Len; i++) Data[i] = vec.Data[i];
}



double TVector:: operator [](size_t index) const
{
	return Data[index];
}




double& TVector::operator [](size_t index)
{
	return Data[index];
}



TVector& TVector::operator =(const TVector& vec)
{
	if (&vec == this) return *this;
	if (Data != nullptr) delete[] Data;
	Len = vec.Len;
	Data = new double[Len];
	for (int i = 0; i < Len; i++) Data[i] = vec.Data[i];
	return *this;	
}

TVector& TVector:: operator*=(const double chislo)
{
	for (int i = 0; i < Len; i++) Data[i] = chislo * Data[i];
	return *this;
}


TVector operator *(const double chislo, const TVector & vec)
{
	TVector product = TVector(vec);
	product *= chislo;
	return product;
}


