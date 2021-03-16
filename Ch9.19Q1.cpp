#include<iostream>
#include<string_view>
#include<string>

int main()
{
	std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string searchName{};
	std::cin >> searchName;

	bool test{ 0 };
	for (const auto& name : names)
	{
		if (searchName == name)
		{
			std::cout << searchName << " was found. \n";
			test = 1;
		}
	}
	if (test == 0)
		std::cout << searchName << " was not found. \n";
	
	return 0;
}