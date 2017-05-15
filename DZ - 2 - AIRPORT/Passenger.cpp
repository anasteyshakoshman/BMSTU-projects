#include "Passenger.h"
#include "Technology.h"   
#include "Staff.h" 


size_t Passenger::Num = 0;

Passenger::Passenger(const std::string & fio, Flight & voyage)
{
	FIO = fio;
	BigBaggage = false;
	Pet = false;
	Voyage = voyage;
	Location = Voyage.GetDeparture().GetLocation();
	++Num;
	voyage.SetPassenger(*this);
};


Passenger::Passenger(const std::string & fio, Flight & voyage, const int age, const bool bigBaggage, const bool pet)
{
	if (age < 0 || age > 150) throw std::length_error("Uncorrect value of passenger's age");
	Age = age;
	FIO = fio;
	Voyage = voyage;
	BigBaggage = bigBaggage;
	Pet = pet;
	Location = Voyage.GetDeparture().GetLocation();
	++Num;
	voyage.SetPassenger(*this);
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

size_t Passenger::GetNum()
{
	return Num;
};

Passenger::~Passenger()
{
	FIO.erase();
	Location.erase();
	Pet = false;
	BigBaggage = false;
	Age = 0;
	Voyage.Clear();
}

void Passenger::ToFile(std::string name) const
{
	std::ofstream file(name);
	file << "P A S S E N G E R" << n;
	file << "FIO: " << FIO << n;
	file << "Location: " << Location << n;
	file << "Flight: " << Voyage.GetName() << n;
	if (Age) file << "Age: " << Age << n;
	if (BigBaggage) file << "Have big baggage" << n;
	else  file << "Have NOT big baggage" << n;
	if (Pet) file << "Have pet" << n;
	else  file << "Have NOT pet" << n;
	file.close();
};

void Passenger::ToFile(std::ofstream & file) const
{
	file << "FIO: " << FIO << n;
	file << "Location: " << Location << n;
	file << "Flight: " << Voyage.GetName() << n;
	if (Age) file << "Age: " << Age << n;
	if (BigBaggage) file << "Have big baggage" << n;
	else  file << "Have NOT big baggage" << n;
	if (Pet) file << "Have pet" << n;
	else  file << "Have NOT pet" << n;
}
