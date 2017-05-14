#pragma once
#include "Include.h"
#include "Airport.h"

class Staff
{
protected:
	Airport AirPort;
	int Experience;   //стаж работы
	static size_t Num;
	int Pay;   //в долларах

public:

	Staff();

	Staff(Airport & airPort);

	Staff(Airport & airPort, const int experience, int pay);

	size_t GetNum();

	std::string GetName() const;
};


class Pilot : public Staff
{
	bool HighQualification;   
	bool LargePlan;
	static size_t Num;

public:

	Pilot();

	Pilot(Airport & airPort);

	Pilot(Airport & airPort, const int experience, const int pay);

	Pilot(const Pilot & other);

	Pilot & operator =(const Pilot & other);

	bool operator ==(const Pilot & other);

	Pilot(Airport & airPort, const int experience, const int pay, const bool highQualification, const  bool largePlan);

	static size_t GetNum();

	bool GetParam() const;

	friend std::ostream & operator <<(std::ostream & out, const Pilot & obj);
};

std::ostream & operator <<(std::ostream & out, const Pilot & obj);

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

	Stewardess();

	Stewardess(Airport & airPort);

	Stewardess(Airport airPort,  const int experience, const int pay);

	Stewardess(Airport airPort,  const int experience, const int pay, const bool more5Language);

	Stewardess(Airport airPort, const int experience, const int pay, const  bool english, const  bool french, const  bool chinese, const  bool german, const bool russian);
	Stewardess(const Stewardess & other);


	Stewardess & operator =(const Stewardess & other);

	bool operator ==(const Stewardess & other);

	static size_t GetNum();

	bool GetParam() const;

	friend std::ostream & operator <<(std::ostream & out, const Stewardess & obj);
};

std::ostream & operator <<(std::ostream & out, const Stewardess & obj);
