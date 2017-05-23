#include "Flight.h"
#include "Passenger.h"
#include "Technology.h" 
#include "Staff.h"  

size_t Flight::Num = 0;


Flight::Flight(Airport & departure, Airport &  destination)
{
	Departure = departure;
	Destination = destination;
	Name = departure.GetLocation() + " - " + destination.GetLocation();
	destination.SetFlight(*this); 
	departure.SetFlight(*this);    
	++Num;
};



Flight::Flight(std::initializer_list<Airport> & airport)    //{departure, destination}
{
	if (airport.size() > 2) throw std::length_error("Object 'Flight' can have just 2 airports");
	auto it = airport.begin();
	Departure = *it;
	++it;
	Destination = *it;
	Name = airport.begin()->GetLocation() + " - " + airport.end()->GetLocation();
	++Num;
};

void Flight::SetPassenger(const Passenger & human)
{
	if (!Departure.GetSizeBPlans() && human.GetBaggage()) throw std::logic_error("This airport hasn't big plan for going big baggage");
	People.push_back(human);
	Departure.SetPassenger(*this, human);
	Destination.SetPassenger(*this, human);
};


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
	Name = other.Name;
	People = other.People;
	return *this;
};



Flight::Flight(const Flight & other)
{
	Departure = other.Departure;
	Destination = other.Destination;
	People = other.People;
	Name = other.Name;
};

std::ostream & operator <<(std::ostream & out, const Flight & obj)
{
	out << "FLIGHT\n";
	out << "Name : " << obj.Name << n;
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

void Flight::Clear()
{
	Departure.Clear();
	Destination.Clear();
	Name.erase();
	People.clear();
};

Flight::~Flight()
{
	Clear();
};

void Flight::ToFile(std::string name)
{
	std::ofstream file(name);
	file << "F L I G H T" << n;
	file << "Name: " << Name << n;
	file << "Deperture: " << Departure.GetName() << n;
	file << "Destination: "  << Destination.GetName() << n;
	if (!People.empty())
	{
		size_t i = 1;
		for (auto it = People.begin(); it != People.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}
	file.close();
};

void Flight::ToFile(std::ofstream & file) const
{
	file << "F L I G H T" << n;
	file << "Name: " << Name << n;
	file << "Deperture: " << Departure.GetName() << n;
	file << "Destination: " << Destination.GetName() << n;
	if (People.size())
	{
		for (auto it = People.begin(); it != People.end(); ++it)
		{
			it->ToFile(file);
		}
	}	
};

void Flight::SetDeparture(const Airport & air)
{
	Departure = air;
}

void Flight::SetDestination(const Airport & air)
{
	Destination = air;
}

std::string Flight::GetName() const
{
	return Name;
};

std::vector<Passenger> Flight::GetPas() const
{
	return People;
};
