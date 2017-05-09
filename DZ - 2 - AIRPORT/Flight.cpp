#include "Flight.h"

Flight::Flight(const Airport & departure, const Airport &  destination)
{
	Departure = departure;
	Destination = destination;
};

Flight::Flight()
{};

Flight & Flight::operator =(const Flight & other)
{
	if (&other == this) return *this;
	Departure = other.Departure;
	Destination = other.Destination;
	return *this;
};


Flight::Flight(const Flight & other)
{
	Departure = other.Departure;
	Destination = other.Destination;
};

std::ostream & operator <<(std::ostream & out, const Flight & obj)
{
	out << "FLIGHT\n";
	out << "Deperture point : " << obj.Departure.GetName() << " ( " << obj.Departure.GetLocation() << " ) " << "\n";
	out << "Destination point : " << obj.Destination.GetName() << " ( " << obj.Destination.GetLocation() << " ) " << "\n";
	return out;
};

bool Flight::operator==(const Flight & other)
{
	return(Departure == other.Departure && Destination == other.Destination);

};
