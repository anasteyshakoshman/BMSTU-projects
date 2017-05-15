#include "Airport.h"
#include "Flight.h"
#include "Technology.h"
#include "Passenger.h"
#include "Staff.h"  

size_t Airport::Num = 0;

Airport::Airport()
{};


Airport::Airport(const std::string & name, const std::string & location)
{
	Name = name;
	Location = location;
	++Num;
};


size_t Airport::GetNum()
{
	return Num;
};

Airport::Airport(const Airport & other)
{
	Name = other.Name;
	FreePlans = other.FreePlans;
	Location = other.Location;
	Flights = other.Flights;
	BPlans = other.BPlans;
	SPlans = other.SPlans;
};

Airport & Airport::operator =(const Airport & other)
{
	if (&other == this) return *this;
	Name = other.Name;
	FreePlans = other.FreePlans;
	BPlans = other.BPlans;
	SPlans = other.SPlans;
	Location = other.Location;
	Flights = other.Flights;
	return *this;
};

std::ostream & operator <<(std::ostream & out, const  Airport & obj)
{
	out << "                A I R P O R T" << n << n;
	out << "Name :    " << obj.Name << n << n;
	out << "Location :    " << obj.Location << n << n;
	size_t i = 1;
	out << "Flights :" << n;
	for (auto it = obj.Flights.begin(); it != obj.Flights.end(); ++it)
	{
		out << i << ") from " << it->GetDeparture().GetName() << " ( " << it->GetDeparture().GetLocation() << ")";
		out << " to " << it->GetDestination().GetName() << " ( " << it->GetDestination().GetLocation() << ")" << n;
		size_t j = 1;
		if (!it->GetPas().empty())
		{
			for (auto p = it->GetPas().begin(); p != it->GetPas().end(); ++p)
			{
				out << j << ")" << *p << n;
				++j;
			}
		}		
		++i;
	}	
	out << n << n << "Plans :" << n;
	for (auto it = obj.BPlans.begin(); it != obj.BPlans.end(); ++it)
	{
		out << *it << n;
	}
	for (auto it = obj.SPlans.begin(); it != obj.SPlans.end(); ++it)
	{
		out << *it << n;
	}
	out << n << n << "Free plans :    " << obj.FreePlans << n << n << n << n;

	return out;
};

void Airport::SetBPlan(const BigPlan & plan)
{
	BPlans.push_back(plan);
	++FreePlans;
};

bool Airport::GetSizeBPlans() const
{
	return BPlans.empty();
};

void Airport::SetStewardess(const Stewardess & stewardess)
{
	if (BPlans.empty() && SPlans.empty()) throw std::logic_error("This airport haven't plans");
	bool add = false;
	if (stewardess.GetParam())
	{
		size_t i = 0;
		while (i < BPlans.size() && !add)
		{
			if (BPlans[i].SizeStew() < 5)
			{
				BPlans[i].SetStewardess(stewardess); 
				add = true;
			}
			++i;
		}
	}
	if (!add)
	{
		size_t i = 0;
		while (i < SPlans.size() && !add)
		{
			if (SPlans[i].SizeStew() < 3)
			{
				SPlans[i].SetStewardess(stewardess);
				add = true;
			}
			++i;
		}
	}
	if(!add) throw std::logic_error("There aren't more vacancies of stewardesses");
}; 

void Airport::SetPilot(const Pilot & pilot)
{
	if (BPlans.empty() && SPlans.empty()) throw std::logic_error("This airport haven't plans");
	bool add = false;
	if (pilot.GetParam())
	{
		size_t i = 0;
		while (i < BPlans.size() && !add)
		{
			if (BPlans[i].SizeFlyers() < 2)
			{
				BPlans[i].SetPilot(pilot);
				add = true;
			}
			++i;
		}
	}
	if (!add )
	{
		size_t i = 0;
		while (i < SPlans.size() && !add)
		{
			if (SPlans[i].SizeFlyers() < 1)
			{
				SPlans[i].SetPilot(pilot);
				add = true;
			}
			++i;
		}
	}
	if (!add) throw std::logic_error("There aren't more vacancies of pilots");
};

void Airport::SetSPlan(const SmallPlan & plan)
{
	SPlans.push_back(plan);
	++FreePlans;
};

void Airport::SetFlight(const Flight & flight)
{
	if (!FreePlans) throw std::length_error("This airport heven't more plans");
	bool notpersonal = false;
	for (size_t i = 0; i < BPlans.size(); ++i)
	{
		if (BPlans[i].SizeFlyers() != 2 && BPlans[i].SizeStew() != 5) notpersonal = true;

	}
	for (size_t i = 0; i < SPlans.size(); ++i)
	{
		if (SPlans[i].SizeFlyers() != 1 && SPlans[i].SizeStew() != 3) notpersonal = true;
	}
	if (notpersonal) throw std::logic_error("This airport can't has flight, because hasn't personal!");
	Flights.push_back(flight);
	--FreePlans;
	
	 
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

void Airport::Clear()
{
	Name.erase();
	Location.erase();
	Flights.clear();
	BPlans.clear();
	SPlans.clear();
	FreePlans = 0;
};

Airport::~Airport()
{
	Clear();
};

void Airport::ToFile(std::string name) const
{
	std::ofstream file(name);
	file << "A I R P O R T" << n;
	file << "Name:" << n << Name << n;
	file << "Location:" << n << Location << n;
	if (!Flights.empty())
	{
		file << "Flights" << n;
		size_t i = 1;
		for (auto it = Flights.begin(); it != Flights.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}
	if (!BPlans.empty())
	{
		file << "BigPlans" << n;
		size_t i = 1;
		for (auto it = BPlans.begin(); it != BPlans.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}
	if (!SPlans.empty())
	{
		file << "SmallPlans" << n;
		size_t i = 1;
		for (auto it = SPlans.begin(); it != SPlans.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}	
	file << "FreePlans:" << n << FreePlans << n;
	file.close();
};
