#include "Flight.h"
#include "Passenger.h"
#include "Technology.h" 
#include "Staff.h"  

size_t Flight::Num = 0;


Flight::Flight(Airport & departure, Airport &  destination)
{
	Departure = departure;
	Destination = destination;
	destination.SetFlight(*this);
	departure.SetFlight(*this);
	++Num;
};



Flight::Flight(std::initializer_list<Airport> & airport)    //{departure, destination}
{
	if (airport.size() > 2) throw std::length_error("Object 'Flight' can have just 2 parametres");
	auto it = airport.begin();
	Departure = *it;
	++it;
	Destination = *it;
	++Num;
};

void Flight::SetPassenger(const Passenger & human)
{
	People.push_back(human);
}


Flight::Flight()
{};

size_t Flight::GetNum()
{
	return Num;
};

Airport  Flight::GetDeparture() const
{
	return Departure;
};

Airport  Flight::GetDestination() const
{
	return Destination;
};

Flight & Flight::operator =(const Flight & other)
{
	if (&other == this) return *this;
	Departure = other.Departure;
	Destination = other.Destination;
	People = other.People;
	return *this;
};



Flight::Flight(const Flight & other)
{
	Departure = other.Departure;
	Destination = other.Destination;
	People = other.People;
};

std::ostream & operator <<(std::ostream & out, const Flight & obj)
{
	out << "FLIGHT\n";
	out << "Deperture point : " << obj.Departure.GetName() << " ( " << obj.Departure.GetLocation() << " ) " << n;
	out << "Destination point : " << obj.Destination.GetName() << " ( " << obj.Destination.GetLocation() << " ) " << n;
	if (obj.People.size()) out << "All passengers : " << obj.People.size() << n;
	size_t i = 1;
	for (auto it = obj.People.begin(); it != obj.People.end(); ++it)
	{
		out << i << ") " << it->GetFIO() << n;
		++i;
	}
	return out;
};

bool Flight::operator ==(const Flight & other)
{
	return(Departure == other.Departure && Destination == other.Destination);
};