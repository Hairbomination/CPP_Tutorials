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

static constexpr int lowest_grade = 0;
static constexpr int highest_grade = 100;

bool grade_within_range(int grade){
	return (grade >= lowest_grade && grade <= highest_grade);
}
int main()
{
	std::cout << "How many students do you want to enter: ";
	static std::size_t numStudents{};
	std::cin >> numStudents;
	std::vector<Student> student_list(numStudents);
	
	for (std::size_t student{0}; student < numStudents; ++student)
	{ 
		std::cout << "Enter student " << student+1 << " name: ";
		std::cin >> student_list[student].name;
		while(true)
		{
			std::cout << "Enter student " << student+1 << " grade(0-100): ";
			std::cin >> student_list[student].grade;
			if( grade_within_range( student_list[student].grade ) )
			{
				break;
			}
			std::cout << "grade given is out of range of correct grades\n";
		}
	}
	std::sort(student_list.begin(), student_list.end(), greater);

	for (auto& student : student_list)
	{
		std::cout << student.name << " got a grade of " << student.grade << '\n';
	}
	
	return 0;
}