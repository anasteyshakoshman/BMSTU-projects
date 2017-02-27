#include "TPoint.h"
#include "TPoint3D.h"


int main()
{
	TPoint * point = new TPoint(3.5, 9.2);
	TPoint3D * point3d = new TPoint3D(7.3, 8.1, 4.9);
	TPoint3D * point3d_2 = new TPoint3D(6.3, 5.8, 1.7);
	std::cout << "Point : " << std::endl;
	point->Print();
	std::cout << std::endl << "Point3d : " << std::endl;
	point3d->Print();
	std::cout << std::endl << "Point3d_2 : " << std::endl;
	point3d_2->Print();
	delete point;
	delete point3d;
	delete point3d_2;
	system("pause");
	return 0;
}
