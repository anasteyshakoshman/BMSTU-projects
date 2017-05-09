#pragma once
#include "Include.h"
#include "Airport.h"

class Staff
{
	Airport AirPort;
	int Experience;   //стаж работы
	static size_t Num;
	int Pay;

public:

	Staff(const Airport & airPort, const int experience, int pay);

	static size_t GetNumStaff();
	
};


class Pilot : public Staff
{
	bool HighQualification;   
	bool LargePlan;
	static size_t Num;

public:

	Pilot(const Airport & airPort, const int experience, const int pay);

	Pilot(const Airport & airPort, const int experience, const int pay, const bool highQualification, const  bool largePlan);

	static size_t GetNum();
};

class Stewardess : public Staff
{
	bool Russian;
	bool English;
	bool French;
	bool Chinese;
	bool German;
	bool More5Language;
	static size_t Num;

public:

	Stewardess(const Airport airPort, const int experience, const int pay);

	Stewardess(const Airport airPort, const int experience, const int pay, const bool more5Language);

	Stewardess(const Airport airPort, const int experience, const int pay, const  bool english, const  bool french, const  bool chinese, const  bool german, const bool russian);

	static size_t GetNum();
};


class TicketSeller : public Staff
{
	static size_t Num;

public:

	TicketSeller(const Airport airPort, const int experience, const int pay);

	static size_t GetNum();
};
