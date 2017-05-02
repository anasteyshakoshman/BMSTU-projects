#include "Header.h"
using namespace std;



int main()
{





	std::vector<Student> students = LoadStudents();

	// find students from G1
	FindStudentGroup finderObj;
	finderObj.neededGroup = "G1";
	auto it = std::find_if(students.begin(), students.end(), finderObj);
	if (it != students.end())
		std::cout << it->FIO << std::endl;


	// find students from G7
	auto ict = std::find_if(students.begin(), students.end(), FindStudentGroup{ "G7" });
	if (ict != students.end()) std::cout << ict->FIO << std::endl;


	// print info about all students
	std::for_each(students.begin(), students.end(), PrinterStudent());


	// count of grades eq 'A' of the student from G7
	auto cnt = std::count_if(it->Grades.begin(), it->Grades.end(), GradeEqual{});
	std::cout << cnt << std::endl;

	// count of grades eq 'B' of the student from G7
	auto cnt2 = std::count_if(it->Grades.begin(), it->Grades.end(),
		// lambda
		[](const std::pair<std::string, Grade> & el)
	{
		return el.second == Grade::B;
	});

	std::cout << cnt2 << std::endl;


	auto WSG = std::for_each(students.begin(), students.end(), WorstSredniBall());
	std::cout << WSG.name << std::endl;

	auto WG = std::for_each(students.begin(), students.end(), WorstGrade());
	std::cout << WG.name << std::endl;

	auto BM = std::for_each(students.begin(), students.end(), BestMathics());
	std::cout << BM.name << std::endl;
	
	std::for_each(students.begin(), students.end(), DutchGrades());

	auto AG = std::for_each(students.begin(), students.end(), AllGroup());
	
	auto MC = std::for_each(students.begin(), students.end(), MathCS());

	std::for_each(students.begin(), students.end(), Literature());

	system("pause");

	return 0;
}



