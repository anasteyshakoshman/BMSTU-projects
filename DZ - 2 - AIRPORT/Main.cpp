#include "Passenger.h"
#include "Airport.h"
#include "Flight.h"
#include "Staff.h"
#include "Include.h"


size_t Staff::Num;
size_t Pilot::Num;
size_t TicketSeller::Num;
size_t Stewardess::Num;



using string = const std::string &;



void Sheme(string locationA, string cityA, const int numPlansA, string locationB, string cityB, const int numPlansB)
{
	Airport A(locationA, cityA, numPlansA);
	Airport B(locationB, cityB, numPlansB);
	Flight AB(A, B);
	std::cout << A << n << B << n;
};

void Sheme2(string locationA, string cityA, const int numPlansA, string locationB, string cityB, const int numPlansB)
{
	Airport A(locationA, cityA, numPlansA);
	Airport B(locationB, cityB, numPlansB);
	Flight AB(A, B);
	Flight Ba(B, A);
	std::cout << A << n << B << n;
};

void Work2()
{
	Airport Tor("Tor", "Minsk", 5);
	Airport Rop("Rop", "Ottava", 4);
	Flight MiOt(Tor, Rop);
	Passenger Po("Po", MiOt);
	Passenger Kim("Kim", MiOt);
	std::cout << Tor << n << Rop << n << MiOt << n << Kim << n;
}

void Work()
{
	Airport Domodevsky("Domodedovsky", "Moscow", 20);
	Airport JohnKennedy("JohnKennedy", "NewYork", 18);
	Airport  BerlinTegel("BerlinTegel", "Berlin", 10);
	Airport  Shoudu("Shoudu", "Beijing", 13);
	std::vector<Flight> flights = 
	{ { Domodevsky, BerlinTegel }, { JohnKennedy, BerlinTegel }, { Domodevsky, JohnKennedy }, { Shoudu, Domodevsky } };
	Passenger John("John", flights[0]);
	Passenger Kit("Kit", flights[1]);
	Passenger Stasiy("Stasiy", flights[2]);
	Passenger Daniel("Daniel", flights[3]);

	std::cout << Domodevsky << n << JohnKennedy << n << BerlinTegel << n << Shoudu << n;

	for (auto it = flights.begin(); it != flights.end(); ++it)
	{
		std::cout << *it << n;
	}
	std::cout << John << n << Kit << n << Stasiy << n << Daniel << n;
};

void main()
{
	Work();
	Sheme("Tunis", "Java", 16, "Pompey", "Tokio", 15);
	Sheme2("Yoko", "Rim", 13, "Roni", "NewDehli", 9);
	Work2();
	std::cout << "All flights: " << Flight::GetNum() << std::endl;
	std::cout << "All airports: " << Airport::GetNum() << std::endl;
	std::cout << "All passengers: " << Passenger::GetNum() << std::endl;
	system("pause");
};
