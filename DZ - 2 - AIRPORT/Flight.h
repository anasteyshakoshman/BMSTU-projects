#pragma once
#include "Include.h"
#include "Airport.h"


class Flight
{
private:
	Airport Departure;  //пункт вылета
	Airport Destination;    //пункт назначения
	

public:

	Flight(const Airport & departure, const Airport &  destination);

	Flight();

	Flight & operator =(const Flight & other);

	Flight(const Flight & other);

	friend std::ostream & operator <<(std::ostream & out, const Flight & obj);

	bool operator==(const Flight & other);
};

std::ostream & operator <<(std::ostream & out, const Flight & obj);
