#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Flight;

class Airport
{
private:

	std::string Name;
	int NumPlans;
	std::string Location;
	std::vector<Flight> Flights;
	static size_t Num;

public:

	Airport();

	Airport(const std::string & name, const std::string & location);


	Airport(const std::string & name, const std::string & location, const int & numplans);

	static size_t GetNum();

	Airport(const Airport & other);

	Airport & operator =(const Airport & other);

	friend std::ostream & operator <<(std::ostream & out, const  Airport & obj);

	bool operator ==(const Airport & other);

	std::string GetLocation() const;

	std::string GetName() const;

	void SetFlight(const Flight & flight);

	void PlusNumPlans();

};

std::ostream & operator <<(std::ostream & out, const  Airport & obj);
