#pragma once
#include "Include.h"
#include "Flight.h"


class Passenger
{
private:

	int Age;
	std::string FIO;
	std::string Location;
	bool BigBaggage;
	bool Pet;
	Flight Voyage;
	static size_t Num;

public:

	Passenger(const std::string & fio, Flight & voyage);

	Passenger(const std::string & fio, Flight & voyage, const int age, bool bigBaggage, bool pet);

	Passenger & operator =(const Passenger & other);

	friend std::ostream & operator <<(std::ostream & out, const  Passenger & obj);

	std::string GetFIO() const;

	bool GetBaggage() const;

	void SetBaggage(const bool baggage);

	static size_t GetNum();
};

std::ostream & operator <<(std::ostream & out, const  Passenger & obj);
