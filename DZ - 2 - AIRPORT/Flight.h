#pragma once
#include "Include.h"
#include "Airport.h"

class Flight
{
private:

	Airport Departure;      
	Airport Destination;    
	static size_t Num;

public:

	Flight(Airport & departure, Airport &  destination);

	Flight();

	Flight(std::initializer_list<Airport> & airport);

	Flight & operator =(const Flight & other);

	Flight(const Flight & other);

	friend std::ostream & operator <<(std::ostream & out, const Flight & obj);

	bool operator ==(const Flight & other);

	static size_t GetNum();

	Airport  GetDeparture() const;

	Airport  GetDestination() const;
};

std::ostream & operator <<(std::ostream & out, const Flight & obj);
