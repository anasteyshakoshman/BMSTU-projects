#include <vector>
#include <map>
#include<set>
#include <algorithm>
#include <numeric>
#include<cmath>
#include <iostream>
#include <string>

enum Grade
{
	F = 1, D, C, B, A
};

struct Student
{
	std::string FIO;
	std::string Group;
	std::map<std::string, Grade> Grades;
	
	void print()
	{
		std::cout << this->FIO << std::endl;
		std::cout << this->Group << std::endl;
		for (auto it = this->Grades.begin(); it != this->Grades.end(); ++it)
		{
			std::cout << it->first << std::endl <<  it->second << std::endl;
		}
	}
};


std::vector<Student> LoadStudents()
{
	using map = std::map<std::string, Grade>;
	map anna =    //по-другому почему то не инициализировалось
	{
		{ "math", Grade::A },    
		{ "cs", Grade::A },
		{ "english", Grade::A },
		{ "dutch", Grade::B },
	};
	map petr =
	{
		{ "math", Grade::A },
		{ "cs", Grade::B },
		{ "dutch", Grade::C },
	};
	map vova =
	{
		{ "math", Grade::F },
		{ "english", Grade::F },
	};
	map vasya =
	{
		{ "math", Grade::F },
		{ "english", Grade::F },
		{ "cs", Grade::B },
		{ "dutch", Grade::C },
	};
	map anton =
	{
		{ "math", Grade::F },
		{ "english", Grade::F },
		{ "dutch", Grade::C },
		{ "cs", Grade::C },
	};
	map masha =
	{
		{ "math", Grade::A },
	};
	map sasha =
	{
		{ "english", Grade::F },
		{ "russian", Grade::F },
		{ "dutch", Grade::F },
	};
	map jecka =
	{
		{ "english", Grade::A },
	};
	map sveta =
	{};

	return
	{
		{
			"Anna", "G7", anna
		},

		{
			"Petr", "G7", petr
		},

		{
			"Vova", "G1", vova
		},

		{
			"Vasya", "G3", vasya
		},
			
		{
			"Anton", "G4", anton
		},

		{
			"Masha", "G2", masha
		},
		{
			"Sasha", "G6", sasha
		},
		{
			"Jeka", "G2", jecka
		},
		{
			"Sveta", "G3", sveta
		}
	};
}


struct FindStudentGroup
{
	std::string neededGroup;
	bool operator()(const Student& s) const
	{
		return s.Group == neededGroup;
	}
};

struct PrinterStudent
{
	void operator()(const Student& s) const
	{
		std::cout << s.FIO << " studies in " << s.Group << std::endl;
	}
};


struct GradeEqual
{
	Grade grade = Grade::A;

	bool operator()(const std::pair<std::string, Grade> & el) const
	{
		return el.second == grade;
	}
};


struct Literature
{
	std::string Str = "Russian Literature";
	void operator()(Student & obj)
	{
		float sum = 0;
		int result;
		size_t k = 0;
		Grade foo;
		auto i = obj.Grades.begin();
		while (i != obj.Grades.end();)
		{
			sum += i->second;
			k++;  ++i;
		}
		if (k) 
		{
			sum /= k;
			result = ceil(sum);
			obj.Grades.insert(std::pair<std::string, Grade>(Str, foo));
		}
		else result = rand() % 5 + 1;
		foo = static_cast<Grade>(result);
		obj.Grades.insert(std::pair<std::string, Grade>(Str, foo));
	}
};

struct BestMathics
{
	std::string name;
	int grade = 0;

	void operator()(Student & obj)
	{
		auto i = obj.Grades.find("math");
		if (i != obj.Grades.end())
		{
			if (!grade || obj.Grades.at("math") > grade)
			{
				name = obj.FIO;
				grade = obj.Grades.at("math");
			}
		}
	}
};

struct WorstSredniBall
{
	std::string name;
	float SredniBall = 0;
	void operator()(Student & obj)
	{
		int sum = 0;
		size_t n = 0;
		auto i = obj.Grades.begin();
		while (i != obj.Grades.end())
		{
			sum += i->second;
			++n;   ++i;
		}
		if (n && (SredniBall > sum / n || !SredniBall))
		{
			name = obj.FIO;
			SredniBall = sum / n;
		}
	}
};

struct WorstGrade
{
	std::string name;
	int n = 0;
	void operator()(Student & obj)
	{
		if (obj.Grades.size() > n)
		{
			name = obj.FIO;
			n = obj.Grades.size();
		}
	}
};

struct DutchGrades
{
	std::string Obj = "dutch";
	void operator()(Student & obj)
	{
		auto i = obj.Grades.find(Obj);
		if (i != obj.Grades.end()) std::cout << obj.FIO << " has grade of dutch :" << i->second << std::endl;
		else std::cout << obj.FIO << " does not learn this object " << std::endl;
	}
};



struct MathCS
{
	std::vector<Student> set;
	void operator()(Student &  obj) 
	{
		auto i = obj.Grades.find("math");
		auto j = obj.Grades.find("cs");
		if (i != obj.Grades.end() && j != obj.Grades.end())
		{
			if (i->second == Grade::B&&j->second == Grade::A) set.push_back(obj);
		}
	}
};

struct AllGroup
{
	std::multimap<std::string, Student> map;

	void operator()(Student& obj)
	{
		map.insert(std::make_pair(obj.Group, obj));
	}
};



//
//Используя функциональные обеъкты и алгоритмы из стандартной библиотеки, найдите:
//
//кто лучше всего знает математику
//у кого худшая средняя оценка за предметы
//кто изучает больше(меньше) всего предметов
//создайте структуру данных, которая по названию группы получит всех учеников в этой группе
//найдите всех учеников, которые знают математику на B, а cs на A
//добавьте всем ученикам новый предмет Russian literature, в качестве оценки поставьте среднюю оценку за все их старые предметы(округлять в большую сторону)
//для всех учеников выведите их оценки по dutch, если студент не изучает это предмет, то вывести об этом сообщение
