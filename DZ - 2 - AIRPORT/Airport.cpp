#include "Airport.h"
#include "Flight.h"
#include "Technology.h"
#include "Passenger.h"
#include "Staff.h"  

size_t Airport::Num = 0;

Airport::Airport()
{};


Airport::Airport(const std::string & name, const std::string & location)
{
	Name = name;
	Location = location;
	++Num;
};


size_t Airport::GetNum()
{
	return Num;
};

Airport::Airport(const Airport & other)
{
	Name = other.Name;
	FreePlans = other.FreePlans;
	Location = other.Location;
	Flights = other.Flights;
	BPlans = other.BPlans;
	SPlans = other.SPlans;
};

Airport & Airport::operator =(const Airport & other)
{
	if (&other == this) return *this;
	Name = other.Name;
	FreePlans = other.FreePlans;
	BPlans = other.BPlans;
	SPlans = other.SPlans;
	Location = other.Location;
	Flights = other.Flights;
	return *this;
};

std::ostream & operator <<(std::ostream & out, const  Airport & obj)
{
	out << "                A I R P O R T" << n << n;
	out << "Name :    " << obj.Name << n << n;
	out << "Location :    " << obj.Location << n << n;
	size_t i = 1;
	out << "Flights :" << n;
	for (auto it = obj.Flights.begin(); it != obj.Flights.end(); ++it)
	{
		out << i << ") from " << it->GetDeparture().GetName() << " ( " << it->GetDeparture().GetLocation() << ")";
		out << " to " << it->GetDestination().GetName() << " ( " << it->GetDestination().GetLocation() << ")" << n;
		size_t j = 1;
		if (it->GetPas().size())
		{
			for (auto p = it->GetPas().begin(); p != it->GetPas().end(); ++p)
			{
				out << j << ")" << *p << n;
				++j;
			}
		}		
		++i;
	}	
	out << n << n << "Plans :" << n;
	for (auto it = obj.BPlans.begin(); it != obj.BPlans.end(); ++it)
	{
		out << *it << n;
	}
	for (auto it = obj.SPlans.begin(); it != obj.SPlans.end(); ++it)
	{
		out << *it << n;
	}
	out << n << n << "Free plans :    " << obj.FreePlans << n << n << n << n;

	return out;
};

void Airport::SetBPlan(const BigPlan & plan)
{
	BPlans.push_back(plan);
	++FreePlans;
};

void Airport::SetPassenger(Flight & flight, const Passenger & human)
{
	for (auto it = Flights.begin(); it != Flights.end(); ++it)
	{
		if (*it == flight)
		{
			{
				it->SetPassenger(human);
				return;
			}
		}
	}
};

bool Airport::GetSizeBPlans() const
{
	return BPlans.size();
};

void Airport::SetStewardess(const Stewardess & stewardess)
{
	if (BPlans.empty() && SPlans.empty()) throw std::logic_error("This airport haven't plans");
	bool add = false;
	if (stewardess.GetParam())
	{
		size_t i = 0;
		while (i < BPlans.size() && !add)
		{
			if (BPlans[i].SizeStew() < 5)
			{
				BPlans[i].SetStewardess(stewardess); 
				add = true;
			}
			++i;
		}
	}
	if (!add)
	{
		size_t i = 0;
		while (i < SPlans.size() && !add)
		{
			if (SPlans[i].SizeStew() < 3)
			{
				SPlans[i].SetStewardess(stewardess);
				add = true;
			}
			++i;
		}
	}
	if(!add) throw std::logic_error("There aren't more vacancies of stewardesses");
}; 

void Airport::SetPilot(const Pilot & pilot)
{
	if (BPlans.empty() && SPlans.empty()) throw std::logic_error("This airport haven't plans");
	bool add = false;
	if (pilot.GetParam())
	{
		size_t i = 0;
		while (i < BPlans.size() && !add)
		{
			if (BPlans[i].SizeFlyers() < 2)
			{
				BPlans[i].SetPilot(pilot);
				add = true;
			}
			++i;
		}
	}
	if (!add )
	{
		size_t i = 0;
		while (i < SPlans.size() && !add)
		{
			if (SPlans[i].SizeFlyers() < 1)
			{
				SPlans[i].SetPilot(pilot);
				add = true;
			}
			++i;
		}
	}
	if (!add) throw std::logic_error("There aren't more vacancies of pilots");
};

void Airport::SetSPlan(const SmallPlan & plan)
{
	SPlans.push_back(plan);
	++FreePlans;
};

void Airport::SetFlight(const Flight & flight)
{
	if (!FreePlans) throw std::length_error("This airport heven't more plans");
	bool notpersonal = false;
	for (size_t i = 0; i < BPlans.size(); ++i)
	{
		if (BPlans[i].SizeFlyers() != 2 && BPlans[i].SizeStew() != 5) notpersonal = true;
	}
	for (size_t i = 0; i < SPlans.size(); ++i)
	{
		if (SPlans[i].SizeFlyers() != 1 && SPlans[i].SizeStew() != 3) notpersonal = true;
	}
	if (notpersonal) throw std::logic_error("This airport can't has flight, because hasn't personal!");
	Flights.push_back(flight);
	--FreePlans;	 
};

bool Airport::operator ==(const Airport & other)
{
	return (Name == other.Name);
};

std::string Airport::GetLocation() const
{
	return Location;
};

std::string Airport::GetName() const
{
	return Name;
};

void Airport::Clear()
{
	Name.erase();
	Location.erase();
	Flights.clear();
	BPlans.clear();
	SPlans.clear();
	FreePlans = 0;
};

Airport::~Airport()
{
	Clear();
};

void Airport::SetName(const std::string name)
{
	Name = name;
};

void Airport::SetLocation(const std::string loc)
{
	Location = loc;
};

void Airport::SetFreePlans(const int num)
{
	FreePlans = num;
};


void Airport::ToFile(const std::string name) const
{
	std::ofstream file(name);
	file << "A I R P O R T" << n;
	file << "Name: " << Name << n;
	file << "Location: "  << Location << n;
	file << "FreePlans: " << FreePlans << n;
	if (!BPlans.empty())
	{
		file << "BigPlans" << n;
		for (auto it = BPlans.begin(); it != BPlans.end(); ++it)
		{
			it->ToFile(file);
		}
	}
	if (!SPlans.empty())
	{
		file << "SmallPlans" << n;
		for (auto it = SPlans.begin(); it != SPlans.end(); ++it)
		{
			it->ToFile(file);
		}
	}
	if (!Flights.empty())
	{
		file << "Flights" << n;
		for (auto it = Flights.begin(); it != Flights.end(); ++it)
		{
			it->ToFile(file);
		}
	}	
	file.close();
};

std::string Airport::Sheme(const std::string line) const
{
	std::string value;
	bool dvoetochie = false, probel = false;
	for (size_t i = 0; i < line.size(); ++i)
	{
		if (line[i] == ':') dvoetochie = true;
		if (line[i] == ' ' && dvoetochie) probel = true;
		else if (dvoetochie && probel) value += line[i];
	}
	return value;
};



void Airport::FromFile(const std::string & way)
{
	std::ifstream file;
	file.open(way);
	if (!file.is_open()) throw std::exception("Can't open this file");
	std::string line;
	getline(file, line);
	if (line == "A I R P O R T")
	{
		getline(file, line);
		SetName(Sheme(line));
		getline(file, line);
		SetLocation(Sheme(line));
		getline(file, line);
		SetFreePlans(stoi(Sheme(line)));
		getline(file, line);
		while (!file.eof())
		{
			if (line == "Flights")
			{
				getline(file, line);
				while (line == "F L I G H T")
				{
					Flight A;
					getline(file, line);
					std::string name = Sheme(line), city_dep, city_des;
					size_t k = 0;
					for (size_t i = 0; i < name.size(); ++i)
					{
						if (name[i] == '-') ++k;
						else if (k) city_des += name[i];
						else city_dep += name[i];						
					}
					getline(file, line);
					if (Sheme(line) == GetName())
					{
						A.SetDeparture(*this);
						getline(file, line);
						A.SetDestination(Airport(Sheme(line), city_des));
					}
					else
					{
						A.SetDeparture(Airport(Sheme(line), city_dep));
						getline(file, line);
						A.SetDestination(*this);
					}
					SetFlight(A);
					getline(file, line);
				}
			}
			else if (line == "BigPlans")
			{
				getline(file, line);
				while (line == "B I G P L A N")
				{
					BigPlan Q;
					getline(file, line);
					if (Sheme(line) == GetName()) Q.SetAir(*this);
					else throw std::logic_error("This big plan must be belong in this airport");
					getline(file, line);
					Q.SetNumPas(stoi(Sheme(line)));
					SetBPlan(Q);
					getline(file, line);
					if (line == "Pilots")
					{
						getline(file, line);
						while (line == "P I L O T")
						{
							Pilot P;
							getline(file, line);
							P.SetPay(stoi(Sheme(line)));
							getline(file, line);
							P.SetExpr(stoi(Sheme(line)));
							getline(file, line);
							P.SetQual(true);
							getline(file, line);
							P.SetLargePlan(true);
							SetPilot(P);
							getline(file, line);
						}
					}
					if (line == "Stewardesses")
					{
						getline(file, line);
						while (line == "S T E W A R D E S S")
						{
							Stewardess K;
							getline(file, line);
							K.SetPay(stoi(Sheme(line)));
							getline(file, line);
							K.SetExpr(stoi(Sheme(line)));
							getline(file, line);
							K.SetLanguage(true);
							SetStewardess(K);
							getline(file, line);
						}
					}
				}
			}
			else if (line == "SmallPlans")
			{
				getline(file, line);
				while (line == "S M A L L P L A N")
				{
					SmallPlan Z;
					getline(file, line);
					if (Sheme(line) == GetName()) Z.SetAir(*this);
					else throw std::logic_error("This big plan must be belong in this airport");
					getline(file, line);
					Z.SetNumPas(stoi(Sheme(line)));
					getline(file, line);
					Z.SetBisness(line == "Bisness class");
					SetSPlan(Z);
					getline(file, line);
					if (line == "Pilots")
					{
						getline(file, line);
						while (line == "P I L O T")
						{
							Pilot P;
							getline(file, line);
							P.SetPay(stoi(Sheme(line)));
							getline(file, line);
							P.SetExpr(stoi(Sheme(line)));
							getline(file, line);
							P.SetLargePlan(line == "The ability to operate large plan");
							getline(file, line);
							P.SetQual(line == "High Qualification");
							SetPilot(P);
							getline(file, line);
						}
					}
					if (line == "Stewardesses")
					{
						getline(file, line);
						while (line == "S T E W A R D E S S")
						{
							Stewardess K;
							getline(file, line);
							K.SetPay(stoi(Sheme(line)));
							getline(file, line);
							K.SetExpr(stoi(Sheme(line)));
							getline(file, line);
							K.SetEnglish(line == "Know english");
							getline(file, line);
							K.SetFrench(line == "Know french");
							getline(file, line);
							K.SetGerman(line == "Know german");
							getline(file, line);
							K.SetRussian(line == "Know russian");
							getline(file, line);
							K.SetChinese(line == "Know chinese");
							SetStewardess(K);
							getline(file, line);
						}
					}
				}
			}
		}
	}
	else throw std::logic_error("Uncorrect type of file");
	file.close();
};




