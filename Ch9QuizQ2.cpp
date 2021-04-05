#include<iostream>
#include<string>
#include<cstddef>
#include<vector>
#include<algorithm>

struct Students
{
	std::string name{};
	int grade{};
};

bool greater(Students a, Students b)
{
	return(a.grade > b.grade);
}

int main()
{
	std::cout << "How many students do you want to enter: ";
	std::size_t numStudents{};
	std::cin >> numStudents;
	std::vector<Students> array(numStudents);
	
	for (std::size_t iterate{0}; iterate != numStudents; ++iterate)
	{ 
		std::cout << "Enter student " << iterate+1 << " name: ";
		std::cin >> array[iterate].name;
		std::cout << "Enter student " << iterate+1 << " grade: ";
		std::cin >> array[iterate].grade;
	}
	std::sort(array.begin(), array.end(), greater);

	for (std::size_t i{ 0 }; i != numStudents; ++i)
	{
		std::cout << array[i].name << " got a grade of " << array[i].grade << '\n';
	}
	
	return 0;
}