#include "Passenger.h"

Passenger::Passenger(const std::string & fio, const Flight & voyage)
{
	FIO = fio;
	BigBaggage = false;
	Pet = false;
	Voyage = voyage;
	++Num;
};


Passenger::Passenger(const std::string & fio, const Flight & voyage, const int age, bool bigBaggage, bool pet)
{
	if (age < 0 || age > 150) throw std::length_error("Uncorrect value of passenger's age");
	Age = age;
	FIO = fio;
	Voyage = voyage;
	BigBaggage = bigBaggage;
	Pet = pet;
	++Num;
};

Passenger & Passenger::operator =(const Passenger & other)
{
	Age = other.Age;
	Voyage = other.Voyage;
	BigBaggage = other.BigBaggage;
	Pet = other.Pet;
	return *this;
};


std::ostream & operator <<(std::ostream & out, const  Passenger & obj)
{
	out << "PASSENGER\n";
	out << "FIO : " << obj.FIO << "\n";
	if(obj.Age) out << "Age : " << obj.Age << "\n";
	out << "Flight : from " << obj.Voyage.GetDeparture().GetName() << " (" << obj.Voyage.GetDeparture().GetLocation() << ") ";
	out << " to " << obj.Voyage.GetDestination().GetName() << " (" << obj.Voyage.GetDestination().GetLocation() << ") " << "\n";
	if (obj.BigBaggage) out << "Have big baggage\n";
	else  out << "Have NOT big baggage\n";
	if (obj.Pet) out << "Have pet\n";
	else  out << "Have NOT pet\n";
	return out;
};


int Passenger::GetAge() const
{
	return Age;
};

void Passenger::SetAge(const int age)
{
	if (age < 0 || age > 120) throw std::out_of_range("Uncorrect value of passenger's age");
	Age = age;
};

std::string Passenger::GetFIO() const
{
	return FIO;
};

void Passenger::SetFIO(const std::string & fio)
{
	FIO = fio;
};

bool Passenger::GetBaggage() const
{
	return BigBaggage;
};

void Passenger::SetBaggage(const bool baggage)
{
	BigBaggage = baggage;
};

bool Passenger::GetPet() const
{
	return Pet;
};

void Passenger::SetPet(const bool pet)
{
	Pet = pet;
};

size_t Passenger::GetNum()
{
	return Num;
};
