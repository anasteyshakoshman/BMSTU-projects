#pragma once
#include "Include.h"
#include "Airport.h"

class Passenger;

class Flight
{ 
	Airport Departure;      
	Airport Destination; 
	std::vector<Passenger> People;
	std::string Name;

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

	void SetPassenger(const Passenger & human);

	Airport  GetDestination() const;

	void Clear();

	~Flight();

	void ToFile(std::string name);

	void ToFile(std::ofstream & file) const;

	std::vector<Passenger> GetPas() const;

	std::string GetName() const;

	void SetDeparture(const Airport & air);

	void SetDestination(const Airport & air);
};

std::ostream & operator <<(std::ostream & out, const Flight & obj);
