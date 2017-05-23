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

void Staff::Clear()
{
	AirPort.Clear();
	Experience = 0;
	Pay = 0;
}

Staff::~Staff()
{
	Clear();
};

void Staff::SetPay(const int pay)
{
	Pay = pay;
};

void Staff::SetExpr(const int expr)
{
	Experience = expr;
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

void Pilot::SetQual(const bool qual)
{
	HighQualification = qual;
};

void Pilot::SetLargePlan(const bool log)
{
	LargePlan = log;
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

Pilot::~Pilot()
{
	Clear();
	HighQualification = false;
	LargePlan = false;
}

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
		if (obj.English) out << "Know english" << n;
		if (obj.French) out << "Know french" << n;
		if (obj.German) out << "Know german" << n;
		if (obj.Russian) out << "Know russian" << n;
		if (obj.Chinese) out << "Know chinese" << n;
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

void Stewardess::SetLanguage(const bool lang)
{
	More5Language = lang;
	English = true;
	Russian = true;
	German = true;
	Chinese = true;
	French = true;
};

void Stewardess::SetEnglish(const bool lang)
{
	English = lang;
};

void Stewardess::SetFrench(const bool lang)
{
	More5Language = false;
	French = lang;
};

void Stewardess::SetChinese(const bool lang)
{
	More5Language = false;
	Chinese = lang;
};

void Stewardess::SetRussian(const bool lang)
{
	More5Language = false;
	Russian = lang;
};

void Stewardess::SetGerman(const bool lang)
{
	More5Language = false;
	German = lang;
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


Stewardess::~Stewardess()
{
	Clear();
	Russian = false;
	German = false;
	Chinese = false;
	English = false;
	French = false;
	More5Language = false;
};

void Stewardess::ToFile(std::string name) const
{
	std::ofstream file(name);
	file << "S T E W A R D E S S" << n;
	if (Pay) file << "Pay : " << Pay << n;
	if (Experience) file << "Experience: " << Experience << n;
	if (More5Language) file << "Know more than 5 language" << n;
	else
	{
		if (English) file << "Know english" << n;
		if (French) file << "Know french" << n;
		if (German) file << "Know german" << n;
		if (Russian) file << "Know russian" << n;
		if (Chinese) file << "Know chinese" << n;
	}
	file.close();
};

void Pilot::ToFile(std::string name) const
{
	std::ofstream file(name);
	file << "P I L O T" << n;
	if (Pay) file << "Pay : " << Pay << n;
	if (Experience) file << "Experience : " << Experience << n;
	if (LargePlan) file << "The ability to operate large plan" << n;
	if (HighQualification) file << "High Qualification" << n;
	file.close();
};

void Pilot::ToFile(std::ofstream & file) const
{
	file << "P I L O T" << n;
	if (Pay) file << "Pay : " << Pay << n;
	if (Experience) file << "Experience : " << Experience << n;
	if (LargePlan) file << "The ability to operate large plan" << n;
	else file << "Hasn't ability to operate large plan" << n;
	if (HighQualification) file << "High Qualification" << n;
	else file << "Hasn't high qualification" << n;
}



void Stewardess::ToFile(std::ofstream & file) const
{
	file << "S T E W A R D E S S" << n;
	file << "Pay : " << Pay << n;
	file << "Experience: " << Experience << n;
	if (More5Language) file << "Know more than 5 language" << n;
	else
	{
		if (English) file << "Know english" << n;
		else  file << "Don't know english" << n;
		if (French) file << "Know french" << n;
		else  file << "Don't know french" << n;
		if (German) file << "Know german" << n;
		else  file << "Don't know german" << n;
		if (Russian) file << "Know russian" << n;
		else  file << "Don't know russian" << n;
		if (Chinese) file << "Know chinese" << n;
		else  file << "Don't know chinese" << n;
	}
};



