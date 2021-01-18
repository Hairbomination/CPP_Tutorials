#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin, name);
	std::cout << "Now enter your age: ";
	float age{};
	std::cin >> age;
	std::cout << "You've lived " << age / name.length() << " years for each letter in your name. \n";

	return 0;
}