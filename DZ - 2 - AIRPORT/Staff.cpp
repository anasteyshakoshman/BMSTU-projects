#include "Staff.h"
#include "Flight.h"
#include "Technology.h"
#include "Passenger.h"


size_t Staff::Num = 0;
size_t Pilot::Num = 0;
size_t Stewardess::Num = 0;

Staff::Staff()
{};

Staff::Staff(Airport & airPort) : AirPort(airPort)
{
	Experience = 1;
	Pay = 80;
	++Num;
};

Staff::Staff(Airport & airPort,  const int experience, int pay) : AirPort(airPort),  Experience(experience), Pay(pay)
{
	++Num;
};

size_t Staff::GetNum()
{
	return Num;
};



Pilot::Pilot()
{};

Pilot::Pilot(Airport & airPort) : Staff(airPort)
{
	LargePlan = false;
	HighQualification = false;
	airPort.SetPilot(*this);
	++Num;
};



Pilot::Pilot(const Pilot & other)
{
	AirPort = other.AirPort;
	HighQualification = other.HighQualification;
	LargePlan = other.LargePlan;
	Experience = other.Experience;
	Pay = other.Pay;
};

Pilot & Pilot::operator =(const Pilot & other)
{
	if (&other == this) return *this;
	AirPort = other.AirPort;
	HighQualification = other.HighQualification;
	LargePlan = other.LargePlan;
	Experience = other.Experience;
	Pay = other.Pay;
	return *this;
};

bool Pilot::operator ==(const Pilot & other)
{
	return(HighQualification == other.HighQualification && LargePlan == other.LargePlan && Experience == other.Experience && Pay == other.Pay);
};

Pilot::Pilot(Airport & airPort,  const int experience, const int pay, const bool highQualification, const  bool largePlan) : Staff(airPort, experience, pay)
{
	HighQualification = highQualification;
	LargePlan = largePlan;
	airPort.SetPilot(*this);
	++Num;
};

size_t Pilot::GetNum()
{
	return Num;
};

bool Pilot::GetParam() const
{
	return HighQualification && LargePlan;
};

std::ostream & operator <<(std::ostream & out, const Pilot & obj)
{
	out << "PILOT" << n;
	if (obj.Pay) out << "Pay : " << obj.Pay << n;
	if (obj.Experience) out << "Experience : " << obj.Experience << n;
	if (obj.LargePlan) out << "The ability to operate large plan" << n;
	if (obj.HighQualification) out << "High Qualification" << n;
	return out;
};

std::ostream & operator <<(std::ostream & out, const Stewardess & obj)
{
	out << "STEWARDESS" << n;
	if (obj.Pay) out << "Pay : " << obj.Pay << n;
	if (obj.Experience) out << "Experience : " << obj.Experience << n;
	if (obj.More5Language) out << "Know more than 5 language" << n;
	else
	{
		if (obj.English) out << "Know english language" << n;
		if (obj.French) out << "Know french language" << n;
		if (obj.German) out << "Know german language" << n;
		if (obj.Russian) out << "Know russian language" << n;
		if (obj.Chinese) out << "Know chinese language" << n;
	}
	return out;
};

Stewardess::Stewardess()
{};

Stewardess::Stewardess(Airport & airPort) : Staff(airPort, 3, 100)
{
	English = true;
	Russian = false;
	French = false;
	German = false;
	Chinese = false;
	More5Language = false;
	++Num;
	airPort.SetStewardess(*this);
};

Stewardess::Stewardess(Airport & airPort,  const int experience, const int pay) : Staff(airPort, experience, pay)
{
	English = true;
	Russian = false;
	French = false;
	German = false;
	Chinese = false;
	More5Language = false;
	++Num;
	airPort.SetStewardess(*this);
};

Stewardess::Stewardess(Airport & airPort,  const int experience, const int pay, const bool more5Language) : Staff(airPort, experience, pay)
{
	More5Language = more5Language;
	English = true;
	if (More5Language)
	{
		Russian = true;
		French = true;
		German = true;
		Chinese = true;
	}
	else
	{
		Russian = false;
		French = false;
		German = false;
		Chinese = false;
	}
	++Num;
	airPort.SetStewardess(*this);
};

Stewardess::Stewardess(Airport & airPort,  const int experience, const int pay, const  bool english, const  bool french, const  bool chinese, const  bool german, const bool russian) : Staff(airPort, experience, pay)
{
	Russian = russian;
	English = english;
	French = french;
	Chinese = chinese;
	German = german;
	More5Language = false;
	++Num;
	airPort.SetStewardess(*this);
};

bool Stewardess::GetParam() const
{
	return (Experience > 5) && More5Language;
};

Stewardess::Stewardess(const Stewardess & other)
{
	AirPort = other.AirPort;
	Russian = other.Russian;
	English = other.English;
	French = other.French;
	Chinese = other.Chinese;
	German = other.German;
	More5Language = other.More5Language;
	Experience = other.Experience;
	Pay = other.Pay;
};

Stewardess & Stewardess::operator =(const Stewardess & other)
{
	if (this == &other) return *this;
	AirPort = other.AirPort;
	Russian = other.Russian;
	English = other.English;
	French = other.French;
	Chinese = other.Chinese;
	German = other.German;
	More5Language = other.More5Language;
	Experience = other.Experience;
	Pay = other.Pay;
	return *this;
};

bool Stewardess::operator ==(const Stewardess & other)
{
	return (Russian == other.Russian &&	English == other.English &&	French == other.French && Chinese == other.Chinese\
		&& German == other.German && More5Language == other.More5Language && Experience == other.Experience && Pay == other.Pay);
};

size_t Stewardess::GetNum()
{
	return Num;
};



