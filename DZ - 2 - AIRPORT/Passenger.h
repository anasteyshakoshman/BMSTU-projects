#pragma once
#include "Include.h"
#include "Flight.h"


class Passenger
{
private:

	int Age;
	std::string FIO;
	bool BigBaggage;
	bool Pet;
	Flight Voyage;
	static size_t Num;

public:

	Passenger(const std::string & fio, const Flight & voyage);

	Passenger(const std::string & fio, const Flight & voyage, const int age, bool bigBaggage, bool pet);

	Passenger & operator = (const Passenger & other);

	friend std::ostream & operator <<(std::ostream & out, const  Passenger & obj);

	int GetAge() const;

	void SetAge(const int age);

	std::string GetFIO() const;

	void SetFIO(const std::string & fio);

	bool GetBaggage() const;

	void SetBaggage(const bool baggage);

	bool GetPet() const;

	void SetPet(const bool pet);

	static size_t GetNum();
};

std::ostream & operator <<(std::ostream & out, const  Passenger & obj);
