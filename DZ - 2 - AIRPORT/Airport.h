#pragma once
#include "Include.h"
#include "Flight.h"

class Airport
{
private:

	std::string Name;
	int NumPlan;
	std::string Location;
	std::vector<Flight> Flights;
	static size_t Num;

public:

	Airport();
	
	Airport(const std::string & name, const std::string & location);

	Airport(const std::string & name, const std::string & location, const int & numplan, const std::vector<Flight> & flights);

	static size_t GetNumAirports();

	Airport(const Airport & other);

	Airport & operator =(const Airport & other);

	friend std::ostream & operator <<(std::ostream & out, const  Airport & obj);

	bool operator ==(const Airport & other);

	std::string GetLocation() const;

	std::string GetName() const;
};

std::ostream & operator <<(std::ostream & out, const  Airport & obj);
