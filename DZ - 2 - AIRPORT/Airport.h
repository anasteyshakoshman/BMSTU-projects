#pragma once
#include "Include.h" 

class Flight;
class BigPlan;
class SmallPlan;
class Stewardess;
class Pilot;

class Airport
{
private:

	std::string Name;
	std::string Location;
	std::vector<Flight> Flights;
	std::vector<BigPlan> BPlans;
	std::vector<SmallPlan> SPlans;
	static size_t Num;
	int FreePlans;

public:

	Airport();

	Airport(const std::string & name, const std::string & location);

	static size_t GetNum();

	Airport(const Airport & other);

	Airport & operator =(const Airport & other);

	friend std::ostream & operator <<(std::ostream & out, const  Airport & obj);

	bool operator ==(const Airport & other);

	std::string GetLocation() const;

	std::string GetName() const;

	void SetFlight(const Flight & flight);

	void SetBPlan(const BigPlan & plan);

	void SetSPlan(const SmallPlan & plan);

	void SetPilot(const Pilot & flyer);

	void SetStewardess(const Stewardess & stewardess);

	bool GetSizeBPlans() const;
};

std::ostream & operator <<(std::ostream & out, const  Airport & obj);
