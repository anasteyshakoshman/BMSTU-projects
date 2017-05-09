#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "Airport.h"


class Flight
{
private:

	Airport Departure;      //пункт вылета
	Airport Destination;    //пункт назначения
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
