#include "Airport.h"
#include "Flight.h"

size_t Airport::Num = 0;

Airport::Airport() {};

Airport::Airport(const std::string & name, const std::string & location)
{
	Name = name;
	Location = location;
	NumPlans = 0;  //так как вызывая этот конструктор, имеется ввиду, что еще будут добавлены рейсы, а следовательно увеличено число самолетов
	++Num;
};



Airport::Airport(const std::string & name, const std::string & location, const int & numplans)
{
	if (numplans < 0) throw std::length_error("The quantity of plans can't be negative");
	Name = name;
	Location = location;
	NumPlans = numplans;
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
	++Num;
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
	out << "Name of airport : " << obj.Name << "\n";
	out << "Location : " << obj.Location << "\n";
	size_t i = 1;
	if (!obj.Flights.empty())
	{
		for (auto it = obj.Flights.begin(); it != obj.Flights.end(); ++it)
		{
			out << "Flight " << i << " : from " << it->GetDeparture().GetName() << " ( " << it->GetDeparture().GetLocation() << ")  to " << it->GetDestination().GetName() << " ( " << it->GetDestination().GetLocation() << ")\n";
			++i;
		}
	}	
	if (obj.NumPlans) out << "Quantity of plans : " << obj.NumPlans << "\n";
	return out;
};

void Airport::SetFlight(const Flight & flight)
{
	Flights.push_back(flight);
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

void Airport::PlusNumPlans()
{
	++NumPlans;
};


