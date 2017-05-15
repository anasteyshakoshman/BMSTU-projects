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

Techology::~Techology()
{
	Inhere.Clear();
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

void Plan::Clear()
{
	Inhere.Clear();
	Hostess.clear();
	Flyers.clear();
	MaxPas = 0;
};

Plan::~Plan()
{
	Clear();
};

BigPlan::~BigPlan()
{
	Clear();
};

SmallPlan::~SmallPlan()
{
	Clear();
	BisnessClass = false;
};

BigPlan::BigPlan(Airport & inhere) : Plan(inhere,  700)
{
	++Num;
	inhere.SetBPlan(*this);
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
	BisnessClass = bisnessclass;
	++Num;
	inhere.SetSPlan(*this);
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


void BigPlan::ToFile(std::string name) const
{
	std::ofstream file(name);
	file << "B I G P L A N" << n;
	file << "Belong: " << Inhere.GetName() << n;
	file << "Max number of passengers: " << MaxPas << n;
	if (Flyers.size())
	{
		file << "Pilots" << n;
		size_t i = 1;
		for (auto it = Flyers.begin(); it != Flyers.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hasn't pilots" << n;
	if (Hostess.size())
	{
		file << "Stewardesses" << n;
		size_t i = 1;
		for (auto it = Hostess.begin(); it != Hostess.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hasn't stewardesses" << n;
	file.close();
};



void SmallPlan::ToFile(std::string name) const
{
	std::ofstream file(name);
	file << "S M A L L P L A N" << n;
	file << "Belong: " << Inhere.GetName() << n;
	file << "Max number of passengers: " << MaxPas << n;
	if (BisnessClass) file << "Bisness Class" << n;
	if (Flyers.size())
	{
		file << "Pilots" << n;
		size_t i = 1;
		for (auto it = Flyers.begin(); it != Flyers.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hasn't pilots" << n;
	if (Hostess.size())
	{
		file << "Stewardesses" << n;
		size_t i = 1;
		for (auto it = Hostess.begin(); it != Hostess.end(); ++it)
		{
			file << i << ") ";
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hasn't stewardesses" << n;
	file.close();
}

void BigPlan::ToFile(std::ofstream & file) const
{
	file << "B I G P L A N" << n;
	file << "Belong: " << Inhere.GetName() << n;
	file << "Max number of passengers: " << MaxPas << n;
	if (Flyers.size())
	{
		file << "Pilots" << n;
		size_t i = 1;
		for (auto it = Flyers.begin(); it != Flyers.end(); ++it)
		{
			file << i << ") " << n;
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hesn't pilots" << n;
	if (Hostess.size())
	{
		file << "Stewardesses" << n;
		size_t i = 1;
		for (auto it = Hostess.begin(); it != Hostess.end(); ++it)
		{
			file << i << ") " << n;
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hasn't stewardesses" << n;
};

void SmallPlan::ToFile(std::ofstream & file) const
{
	file << "S M A L L P L A N" << n;
	file << "Belong " << Inhere.GetName() << n;
	file << "Max number of passengers :" << MaxPas << n;
	if (Flyers.size())
	{
		file << "Pilots:" << n;
		size_t i = 1;
		for (auto it = Flyers.begin(); it != Flyers.end(); ++it)
		{
			file << i << ") " << n;
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hasn't pilots" << n;
	if (Hostess.size())
	{
		file << "Stewardesses : " << n;
		size_t i = 1;
		for (auto it = Hostess.begin(); it != Hostess.end(); ++it)
		{
			file << i << ") " << n;
			it->ToFile(file);
			++i;
		}
	}
	else file << "Hasn't stewardesses" << n;
};
