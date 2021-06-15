#include<iostream>
#include<string>
#include<cstddef>
#include<vector>
#include<algorithm>

struct Student
{
	std::string name{};
	int grade{};
};

bool greater(const Student& a, const Student& b)
{
	return(a.grade > b.grade);
}

int main()
{
	std::cout << "How many students do you want to enter: ";
	std::size_t numStudents{};
	std::cin >> numStudents;
	std::vector<Student> student_list(numStudents);
	
	for (std::size_t student{0}; student < numStudents; ++student)
	{ 
		std::cout << "Enter student " << student+1 << " name: ";
		std::cin >> student_list[student].name;
		std::cout << "Enter student " << student+1 << " grade: ";
		std::cin >> student_list[student].grade;
	}
	std::sort(student_list.begin(), student_list.end(), greater);

	for (auto& student : student_list)
	{
		std::cout << student.name << " got a grade of " << student.grade << '\n';
	}
	
	return 0;
}