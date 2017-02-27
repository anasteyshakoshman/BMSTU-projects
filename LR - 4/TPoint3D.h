#include "TPoint.h"

class TPoint3D : public TPoint
{
protected:

	float Z;

public:

	TPoint3D() : TPoint(), Z(0.0)         //вызов конструктора базового класса без параметров
	{}

	TPoint3D(float x, float y, float z) : TPoint(x, y), Z(z)   //вызов конструктора базового класса с параметрами
	{}

	virtual void Print()  //Переопределенный метод Print()
	{
		TPoint::Print();
		std::cout << " z = " << Z << std::endl;
	}
};
