#include "Passenger.h"
#include "Airport.h"
#include "Flight.h"
#include "Staff.h"
#include "Include.h"


size_t Passenger::Num;
size_t Staff::Num;
size_t Pilot::Num;
size_t TicketSeller::Num;
size_t Stewardess::Num;


void Work()
{
	Airport Domodevsky("Domodedovsky", "Moscow");
	Airport JohnKennedy("JohnKennedy", "NewYork");
	Airport  BerlinTegel("BerlinTegel", "Berlin");
	Airport  Shoudu("Shoudu", "Beijing");

	

	std::vector<Flight> flights = 
	{ { Domodevsky, BerlinTegel }, { JohnKennedy, BerlinTegel }, { Domodevsky, JohnKennedy }, { Shoudu, Domodevsky } };
	std::cout << Domodevsky << std::endl;
	std::cout << JohnKennedy << std::endl;
	std::cout << BerlinTegel << std::endl;

	for (auto it = flights.begin(); it != flights.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

};

void main()
{
	Work();
	system("pause");
}
