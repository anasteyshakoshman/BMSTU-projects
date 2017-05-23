#pragma once
#include "Airport.h"



class Techology
{
protected:
	Airport Inhere;
	static size_t Num;

public:

	Techology();

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

	Plan();

	Plan(const Airport & inhere, const int maxpas);

	static size_t GetNum();

	void SetStewardess(const Stewardess & hostess);

	void SetPilot(const Pilot & flyer);

	size_t SizeFlyers() const;

	size_t SizeStew() const;	

	void Clear();

	~Plan();

	void SetNumPas(const int num);

};


class BigPlan : public Plan
{
	static size_t Num;

public:

	BigPlan();
	
	BigPlan(Airport & inhere);

	static size_t GetNum();


	friend std::ostream & operator <<(std::ostream & out, const BigPlan & obj);

	~BigPlan();

	void ToFile(std::string name) const;

	void ToFile(std::ofstream & file) const;

	void SetAir(const Airport & inhere);

};
std::ostream & operator <<(std::ostream & out, const BigPlan & obj);

class SmallPlan : public Plan
{
	bool BisnessClass;
	static size_t Num;

public:

	SmallPlan();

	SmallPlan(Airport & inhere, bool bisnessclass);

	static size_t GetNum();

	friend std::ostream & operator <<(std::ostream & out, const SmallPlan & obj);

	~SmallPlan();

	void SetAir(const Airport & inhere);

	void SetBisness(const bool bis);

	void ToFile(std::string name) const;

	void ToFile(std::ofstream & file) const;
};
std::ostream & operator <<(std::ostream & out, const SmallPlan & obj);
