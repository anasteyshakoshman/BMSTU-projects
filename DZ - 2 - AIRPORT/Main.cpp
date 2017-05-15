#include "Passenger.h"
#include "Airport.h"
#include "Flight.h"
#include "Staff.h"
#include "Include.h"
#include "Technology.h"

using string = const std::string &;

void GetNum()
{
	std::cout << "All flights: " << Flight::GetNum() << std::endl;
	std::cout << "All airports: " << Airport::GetNum() << std::endl;
	std::cout << "All technologies: " << Techology::GetNum() << std::endl;
	std::cout << "All big plans: " << BigPlan::GetNum() << std::endl;
	std::cout << "All small plans : " << SmallPlan::GetNum() << std::endl;
	std::cout << "All pilots: " << Pilot::GetNum() << std::endl;
	std::cout << "All stewardesses: " << Stewardess::GetNum() << std::endl;
}

void SPlan(Airport & airport)     //фунукция для создания маленького самолета с персоналом
{
	SmallPlan Q(airport, true);
	Pilot Y(airport, 6, 180, false, false);
	Stewardess I(airport, 4, 100, true, false, true, false, true);
	Stewardess P(airport, 2, 95, false, false, true, true, true);
	Stewardess K(airport, 3, 110, true, true, true, true, false);
}

void BPlan(Airport & airport)  //фунукция для создания большого самолета с персоналом
{
	BigPlan Q(airport);
	Pilot Y(airport, 10, 200, true, true);
	Pilot U(airport, 15, 250, true, true);
	Stewardess K(airport, 8, 130, true);
	Stewardess I(airport, 6, 120, true);
	Stewardess P(airport, 7, 125, true);
	Stewardess E(airport, 10, 150, true);
	Stewardess M(airport, 8, 140, true);
}

void Sheme(string nameA, string cityA, string nameB, string cityB, string fio)
{
	Airport A(nameA, cityA);
	Airport B(nameB, cityB);

	BPlan(A);
	BPlan(B);
	SPlan(A);
	SPlan(B);

	Flight AB(A, B);
	Flight BA(B, A);

	Passenger C(fio, AB);
	
	std::cout << A << n << B  << n << AB << BA << n << C << n;

	A.ToFile("A_airport.txt");
	B.ToFile("B_airport.txt");
};


void Work2()
{
	Airport Tor("Tor", "Minsk");
	Airport Rop("Rop", "Ottava");

	BPlan(Tor);
	BPlan(Rop);
	SPlan(Tor);
	SPlan(Rop);

	Flight MiOt(Tor, Rop);
	Flight OtMi(Rop, Tor);

	Passenger Po("Po", MiOt);
	Passenger Kim("Kim", MiOt);

	std::cout << MiOt << n << OtMi << n;

	std::cout << Tor << n << Rop << n;
}

void Work()
{
	Airport Domodevsky("Domodedovsky", "Moscow");   //создаем аэропорта
	Airport JohnKennedy("JohnKennedy", "NewYork");
	Airport  BerlinTegel("BerlinTegel", "Berlin");
	Airport  Shoudu("Shoudu", "Beijing");

	
	BigPlan R(Domodevsky);  //добавляем самолеты
	BigPlan U(BerlinTegel);
	BigPlan B(Domodevsky);
	BigPlan C(BerlinTegel);
	BigPlan O(Domodevsky);
	BigPlan L(BerlinTegel);

	SmallPlan Z(Shoudu, false);
	SmallPlan P(JohnKennedy, true);
	SmallPlan Y(Shoudu, false);
	SmallPlan I(JohnKennedy, true);

	for (int i = 0; i < 15; ++i)  //добавляем персонал
	{
		Stewardess(Domodevsky, 7, 8, true);
		Stewardess(BerlinTegel, 7, 8, true);
		if (i < 6)
		{
			Pilot(Domodevsky, 7, 250, true, true);
			Pilot(BerlinTegel, 7, 250, true, true);
			if (i < 2)
			{
				Pilot(JohnKennedy, 7, 250, true, true);
				Pilot(Shoudu, 7, 250, true, true);
			}
			Stewardess(JohnKennedy, 7, 8, true);
			Stewardess(Shoudu, 7, 8, true);
		}		
	}

	std::vector<Flight> flights =     //создаем рейсы между аэропортами
	{ { Domodevsky, BerlinTegel }, { JohnKennedy, BerlinTegel }, { Domodevsky, JohnKennedy }, { Shoudu, Domodevsky }, { BerlinTegel, Shoudu } };


	Passenger John("John", flights[0]);     //добалвяем пассжиров
	Passenger Kit("Kit", flights[1]);
	Passenger Lily("Lily", flights[2]);
	Passenger Stasiy("Stasiy", flights[2]);
	Passenger Daniel("Daniel", flights[3]);
	Passenger Rick("Rick", flights[0]);
	Passenger Yoko("Yoko", flights[4]);

	std::cout << Domodevsky << n << JohnKennedy << n << BerlinTegel << n << Shoudu << n;

	for (auto it = flights.begin(); it != flights.end(); ++it)
	{
		std::cout << *it << n;
	}
	std::cout << John << n << Kit << n << Stasiy << n << Daniel << Rick << n << Lily << n << Yoko << n;
};


void People()
{
	std::string name1, city1, name2, city2, fio;
	std::cout << "Enter name of Airport 1 : " << n;
	std::cin >> name1;
	std::cout << "Enter name of city 1 : " << n;
	std::cin >> city1;
	std::cout << "Enter name of Airport 2 : " << n;
	std::cin >> name2;
	std::cout << "Enter name of city 2: " << n;
	std::cin >> city2;
	std::cout << "Enter fio of passenger : " << n;
	std::cin >> fio;
	Sheme(name1, city1, name2, city2, fio);
}



void main()
{
	//Work2();
	//People();
	Sheme("Iu", "Moscow", "Polwad", "Polsha", "Tim");
	GetNum();	
	system("pause");
};
