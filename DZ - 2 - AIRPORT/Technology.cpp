#include "Technology.h"
#include "Flight.h"   
#include "Passenger.h"
#include "Staff.h"  

size_t Plan::Num = 0;
size_t BigPlan::Num = 0;
size_t SmallPlan::Num = 0;
size_t Techology::Num = 0;

Techology::Techology(const Airport & inhere)
{
	Inhere = inhere;
	++Num;
};


size_t Techology::GetNum()
{
	return Num;
};

Plan::Plan(const Airport & inhere, const int maxpas) : Techology(inhere)
{
	MaxPas = maxpas;
	++Num;
};

size_t Plan::GetNum()
{
	return Num;
};

void Plan::SetStewardess(const Stewardess & hostess)
{
	Hostess.push_back(hostess);
};



BigPlan::BigPlan(Airport & inhere) : Plan(inhere,  700)
{
	inhere.SetBPlan(*this);
	++Num;
};

size_t BigPlan::GetNum()
{
	return Num;
};

void Plan::SetPilot(const Pilot & flyer)
{
	Flyers.push_back(flyer);
};

size_t Plan::SizeFlyers() const
{
	return Flyers.size();
};

size_t Plan::SizeStew() const
{
	return Hostess.size();
};



SmallPlan::SmallPlan(Airport & inhere,  bool bisnessclass) : Plan(inhere, 60)
{
	inhere.SetSPlan(*this);
	BisnessClass = bisnessclass;
	++Num;
};

size_t SmallPlan::GetNum()
{
	return Num;
};



std::ostream & operator <<(std::ostream & out, const SmallPlan & obj)
{
	out << "    SMALL PLAN" << n;
	out << "Belong " << obj.Inhere.GetName() << n;
	out << "Max number of passengers : " << obj.MaxPas << n; 
	if (obj.BisnessClass) out << "Bisness class" << n;
	else out << "Econom class" << n;
	if (obj.Flyers.size())
	{
		out << "Pilot : " << n;
		for (auto it = obj.Flyers.begin(); it != obj.Flyers.end(); ++it)
		{
			out  << *it << n;
		}
	}
	else out << "Find pilots!!" << n;
	if (obj.Hostess.size())
	{
		out << "Stewardesses : " << n;
		size_t i = 1;
		for (auto it = obj.Hostess.begin(); it != obj.Hostess.end(); ++it)
		{
			out << i << ") " << *it << n;
			++i;
		}
	}	
	else out << "Find stewardesses!!" << n;
	return out;
};

std::ostream & operator <<(std::ostream & out, const BigPlan & obj)
{
	out << "    BIG PLAN" << n;
	out << "Belong " << obj.Inhere.GetName() << n;
	out << "Max number of passengers : " << obj.MaxPas << n;
	if (obj.Flyers.size())
	{
		out << "Pilots : " << n;
		size_t i = 1;
		for (auto it = obj.Flyers.begin(); it != obj.Flyers.end(); ++it)
		{
			out << i << ") " << *it << n;
			++i;
		}
	}
	else out << "Find proffessional pilots!!" << n;
	if (obj.Hostess.size())
	{
		out << "Stewardesses : " << n;
		size_t i = 1;
		for (auto it = obj.Hostess.begin(); it != obj.Hostess.end(); ++it)
		{
			out << i << ") " << *it << n;
			++i;
		}
	}
	else out << "Find professional stewardesses!!" << n;
	return out;
};
