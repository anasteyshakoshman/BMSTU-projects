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

void Sheme(string nameA, string cityA, string nameB, string cityB, string fio)
{
	Airport A(nameA, cityA);
	Airport B(nameB, cityB);
	Flight AB(A, B);
	Flight BA(B, A);
	Passenger C(fio, AB);
	std::cout << A << n << B  << n << AB << BA << n << C << n;
};


void Work2()
{
	Airport Tor("Tor", "Minsk");
	Airport Rop("Rop", "Ottava");

	BigPlan W(Tor);
	SmallPlan M(Rop, true);
	BigPlan I(Rop);
	SmallPlan K(Tor, false);

	for (int i = 0; i < 2; ++i)
	{
		Pilot(Tor, 6, 250, true, true);
		Pilot(Rop, 6, 250, true, true);
	}

	Pilot(Tor, 3, 150, false, false);
	Pilot(Rop, 3, 150, false, false);

	
	for (int i = 0; i < 5; ++i)
	{
		Tor.SetStewardess(Stewardess(Tor, 6, 250, true));
		Rop.SetStewardess(Stewardess(Tor, 6, 250, true));
	}

	for (int i = 0; i < 2; ++i)
	{
		Tor.SetStewardess(Stewardess(Tor, 3, 150, false));
		Rop.SetStewardess(Stewardess(Rop, 3, 150, false));
	}


	Flight MiOt(Tor, Rop);

	Passenger Po("Po", MiOt);
	Passenger Kim("Kim", MiOt);

	std::cout << Tor << n << Rop << n;
}

void Work()
{
	Airport Domodevsky("Domodedovsky", "Moscow");
	Airport JohnKennedy("JohnKennedy", "NewYork");
	Airport  BerlinTegel("BerlinTegel", "Berlin");
	Airport  Shoudu("Shoudu", "Beijing");

	BigPlan R(Domodevsky);
	SmallPlan I(JohnKennedy, true);
	BigPlan U(BerlinTegel);
	SmallPlan Y(Shoudu, false);

	for (int i = 0; i < 2; ++i)
	{
		Pilot(Domodevsky, 7, 250, true, true);
		if(i < 1) Pilot(JohnKennedy, 7, 250, true, true);
		Pilot(BerlinTegel, 7, 250, true, true);
		if(!i)Pilot(Shoudu, 7, 250, true, true);
	}
	for (int i = 0; i < 5; ++i)
	{
		Domodevsky.SetStewardess(Stewardess(Domodevsky, 7, 8, true));
		if (i < 3) JohnKennedy.SetStewardess(Stewardess(JohnKennedy, 7, 8, true));
		BerlinTegel.SetStewardess(Stewardess(BerlinTegel, 7, 8, true));
		if (i < 3) Shoudu.SetStewardess(Stewardess(Shoudu, 7, 8, true));
	}

	BigPlan O(Domodevsky);
	SmallPlan P(JohnKennedy, true);
	BigPlan L(BerlinTegel);
	SmallPlan Z(Shoudu, false);

	for (int i = 0; i < 2; ++i)
	{
		Pilot(Domodevsky, 7, 250, true, true);
		if (!i) Pilot(JohnKennedy, 7, 250, true, true);
		Pilot(BerlinTegel, 7, 250, true, true);
		if (!i)Pilot(Shoudu, 7, 250, true, true);
	}
	for (int i = 0; i < 5; ++i)
	{
		Domodevsky.SetStewardess(Stewardess(Domodevsky, 7, 8, true));
		if (i < 3) JohnKennedy.SetStewardess(Stewardess(Domodevsky, 7, 8, true));
		BerlinTegel.SetStewardess(Stewardess(BerlinTegel, 7, 8, true));
		if (i < 3) Shoudu.SetStewardess(Stewardess(Shoudu, 7, 8, true));
	}

	BigPlan B(Domodevsky);
	BigPlan C(BerlinTegel);

	for (int i = 0; i < 2; ++i)
	{
		Pilot(Domodevsky, 7, 250, true, true);
		Pilot(BerlinTegel, 7, 250, true, true);
	}
	for (int i = 0; i < 5; ++i)
	{
		Domodevsky.SetStewardess(Stewardess(Domodevsky, 7, 8, true));
		BerlinTegel.SetStewardess(Stewardess(BerlinTegel, 7, 8, true));
	}
	

	std::vector<Flight> flights = 
	{ { Domodevsky, BerlinTegel }, { JohnKennedy, BerlinTegel }, { Domodevsky, JohnKennedy }, { Shoudu, Domodevsky }, { BerlinTegel, Shoudu } };
	Passenger John("John", flights[0]);
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
	std::cout << John << n << Kit << n << Stasiy << n << Daniel  << Rick << n << Lily << n;
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
	Work2();
	GetNum();
	
	system("pause");
};
