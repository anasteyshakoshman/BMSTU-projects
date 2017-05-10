#include "Passenger.h"


size_t Passenger::Num = 0;

Passenger::Passenger(const std::string & fio, Flight & voyage)
{
	FIO = fio;
	BigBaggage = false;
	Pet = false;
	Voyage = voyage;
	voyage.SetPassenger(*this);
	Location = Voyage.GetDeparture().GetLocation();
	++Num;
};


Passenger::Passenger(const std::string & fio, Flight & voyage, const int age, const bool bigBaggage, const bool pet)
{
	if (age < 0 || age > 150) throw std::length_error("Uncorrect value of passenger's age");
	Age = age;
	FIO = fio;
	Voyage = voyage;
	voyage.SetPassenger(*this);
	BigBaggage = bigBaggage;
	Pet = pet;
	Location = Voyage.GetDeparture().GetLocation();
	++Num;
};

Passenger & Passenger::operator =(const Passenger & other)
{
	Age = other.Age;
	Voyage = other.Voyage;
	BigBaggage = other.BigBaggage;
	Location = other.Location;
	Pet = other.Pet;
	return *this;
};


std::ostream & operator <<(std::ostream & out, const  Passenger & obj)
{
	out << "PASSENGER\n";
	out << "FIO : " << obj.FIO << n;
	out << "Location : " << obj.Location << n;
	if(obj.Age) out << "Age : " << obj.Age << n;
	out << "Flight : from " << obj.Voyage.GetDeparture().GetName() << " (" << obj.Voyage.GetDeparture().GetLocation() << ") ";
	out << " to " << obj.Voyage.GetDestination().GetName() << " (" << obj.Voyage.GetDestination().GetLocation() << ") " << n;
	if (obj.BigBaggage) out << "Have big baggage\n";
	else  out << "Have NOT big baggage\n";
	if (obj.Pet) out << "Have pet\n";
	else  out << "Have NOT pet\n";
	return out;
};


std::string Passenger::GetFIO() const
{
	return FIO;
};

bool Passenger::GetBaggage() const
{
	return BigBaggage;
};

void Passenger::SetBaggage(const bool baggage)
{
	BigBaggage = baggage;
};

size_t Passenger::GetNum()
{
	return Num;
};
