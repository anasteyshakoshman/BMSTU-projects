#include "Airport.h"
#include "Flight.h"


size_t Airport::Num = 0;

Airport::Airport()
{};


Airport::Airport(const std::string & name, const std::string & location, const int & numplans)
{
	if (numplans < 0) throw std::length_error("The quantity of plans can't be negative");
	Name = name;
	Location = location;
	NumPlans = numplans;
	FreePlans = numplans;
	++Num;
};


size_t Airport::GetNum()
{
	return Num;
};

Airport::Airport(const Airport & other)
{
	Name = other.Name;
	NumPlans = other.NumPlans;
	Location = other.Location;
	Flights = other.Flights;
};

Airport & Airport::operator =(const Airport & other)
{
	if (&other == this) return *this;
	Name = other.Name;
	NumPlans = other.NumPlans;
	Location = other.Location;
	Flights = other.Flights;
	return *this;
};

std::ostream & operator <<(std::ostream & out, const  Airport & obj)
{
	out << "AIRPORT\n";
	out << "Name : " << obj.Name << "\n";
	out << "Location : " << obj.Location << "\n";
	size_t i = 1;
	out << "Quntity of flights : " << obj.Flights.size() << "\n";
	for (auto it = obj.Flights.begin(); it != obj.Flights.end(); ++it)
	{
		out << i << ") from " << it->GetDeparture().GetName() << " ( " << it->GetDeparture().GetLocation() << ")";
		out << " to " << it->GetDestination().GetName() << " ( " << it->GetDestination().GetLocation() << ")\n";
		++i;
	}	
	out << "Quantity of all plans : " << obj.NumPlans << "\n";
	out << "Quantity of free plans : " << obj.FreePlans << "\n";
	return out;
};

void Airport::SetFlight(const Flight & flight)
{
	if (NumPlans - Flights.size() >= 1)
	{
		Flights.push_back(flight);
		--FreePlans;
	}
	else throw std::length_error("This airport heven't more plans");
};

bool Airport::operator ==(const Airport & other)
{
	return (Name == other.Name);
};

std::string Airport::GetLocation() const
{
	return Location;
};

std::string Airport::GetName() const
{
	return Name;
};




