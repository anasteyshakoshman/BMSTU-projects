#include "Staff.h"

Staff::Staff(const Airport & airPort, const int experience, int pay) : AirPort(airPort), Experience(experience), Pay(pay)
{
	++Num;
};

size_t Staff::GetNumStaff()
{
	return Num;
};






Pilot::Pilot(const Airport & airPort, const int experience, const int pay) : Staff(airPort, experience, pay)
{
	++Num;
};

Pilot::Pilot(const Airport & airPort, const int experience, const int pay, const bool highQualification, const  bool largePlan) : Staff(airPort, experience, pay)
{
	HighQualification = highQualification;
	LargePlan = largePlan;
	++Num;
};

size_t Pilot::GetNum()
{
	return Num;
};





Stewardess::Stewardess(const Airport airPort, const int experience, const int pay) : Staff(airPort, experience, pay)
{
	English = true;
	++Num;
};

Stewardess::Stewardess(const Airport airPort, const int experience, const int pay, const bool more5Language) : Staff(airPort, experience, pay)
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
};

Stewardess::Stewardess(const Airport airPort, const int experience, const int pay, const  bool english,\

const  bool french, const  bool chinese, const  bool german, const bool russian) : Staff(airPort, experience, pay)
{
	Russian = russian;
	English = english;
	French = french;
	Chinese = chinese;
	German = german;
	More5Language = false;
	++Num;
};

size_t Stewardess::GetNum()
{
	return Num;
};




TicketSeller::TicketSeller(const Airport airPort, const int experience, const int pay) : Staff(airPort, experience, pay)
{
	++Num;
};

size_t TicketSeller::GetNum()
{
	return Num;
};
