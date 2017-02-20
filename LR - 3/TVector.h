#pragma once
#include <iostream>


class TVector
{
	double * Data;
	int Len;
public:
	TVector();
	TVector(const double * const mus, const size_t count);
	TVector(const TVector & vec);
	~TVector();
	double operator [](size_t index) const;
	double& operator [](size_t index);
	TVector& operator =(const TVector& vec);
	TVector & operator*=(const double chislo);
};

TVector operator *(const double chislo, const TVector & vec);






