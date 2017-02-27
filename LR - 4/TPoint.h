
#include <iostream>
#include <cstdlib>


class TPoint
{

protected:

	float X, Y;

public:

	TPoint() : X(0.0), Y(0.0)
	{}


	TPoint(float x, float y) : X(x), Y(y)
	{}

	virtual void Print()
	{
		std::cout << " x = " << X << "\n y = " << Y << std::endl;
	}
};
