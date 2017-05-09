#include "Airport.h"



Airport::Airport() {};

Airport::Airport(const std::string & name, const std::string & location)
{
	Name = name;
	Location = location;
	++Num;
};

Airport::Airport(const std::string & name, const std::string & location, const int & numplan, const std::vector<Flight> & flights)
{
	if (numplan < 0) throw std::length_error("The quantity of plans can't be negative");
	if (numplan < flights.size()) throw std::length_error("The quantity of plans can't be less than the quantity of fligths");
	Name = name;
	Location = location;
	NumPlan = numplan;
	Flights = flights;
	++Num;
};

size_t Airport::GetNumAirports()
{
	return Num;
};

Airport::Airport(const Airport & other)
{
	Name = other.Name;
	NumPlan = other.NumPlan;
	Location = other.Location;
	Flights = other.Flights;
	++Num;
};

Airport & Airport::operator =(const Airport & other)
{
	if (&other == this) return *this;
	Name = other.Name;
	NumPlan = other.NumPlan;
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
	for (auto it = obj.Flights.begin(); it != obj.Flights.end(); ++it)
	{
		out << "Flights number" << i << " : " << *it << "\n";
		++i;
	}
	return out;
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
