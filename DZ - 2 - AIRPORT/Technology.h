#pragma once
#include "Airport.h"



class Techology
{
protected:
	Airport Inhere;
	static size_t Num;

public:

	Techology(const Airport & inhere);

	static size_t GetNum();

	~Techology();
};

class Pilot;
class Stewardess;


class Plan : public Techology
{
protected:
	std::vector<Pilot> Flyers;
	std::vector<Stewardess> Hostess;
	int MaxPas;
	static size_t Num;

public:

	Plan(const Airport & inhere, const int maxpas);

	static size_t GetNum();

	void SetStewardess(const Stewardess & hostess);

	void SetPilot(const Pilot & flyer);

	size_t SizeFlyers() const;

	size_t SizeStew() const;	

	void Clear();

	~Plan();

};


class BigPlan : public Plan
{
	static size_t Num;

public:
	
	BigPlan(Airport & inhere);

	static size_t GetNum();


	friend std::ostream & operator <<(std::ostream & out, const BigPlan & obj);

	~BigPlan();

};
std::ostream & operator <<(std::ostream & out, const BigPlan & obj);

class SmallPlan : public Plan
{
	bool BisnessClass;
	static size_t Num;

public:

	SmallPlan(Airport & inhere, bool bisnessclass);

	static size_t GetNum();

	friend std::ostream & operator <<(std::ostream & out, const SmallPlan & obj);

	~SmallPlan();

};
std::ostream & operator <<(std::ostream & out, const SmallPlan & obj);
