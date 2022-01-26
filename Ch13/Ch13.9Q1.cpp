#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map{};

public:
	char& operator[](const std::string& index);
};

char& GradeMap::operator[](const std::string& index)	//I remembered to think about consting this function. Decided not to because it changes stuff. Seems to be the right answer.
{
	const auto found{ std::find_if(m_map.begin(), m_map.end(), [&index](StudentGrade search)
		{return (search.name.find(index) != std::string::npos); }) };		//Their lambda: [&](const auto& student){return (student.name == name);})};
	if (found == m_map.end())												//I just copied from the example in the lambda tutorial (11.8)				
	{
		m_map.push_back(StudentGrade{ index, });		//Apparently m_map.push_back({ name }); works. But hey, at least I didn't create an unnecessary variable.
		return m_map.back().grade;
	}
	else
		return found->grade;		//Fuck me, I need to remember how to use the -> operator. Every time I have to do
}									//a member access thing with an iterator I waste hours trying to figure out why 
									//m_map[found].grade doesn't work.
int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}