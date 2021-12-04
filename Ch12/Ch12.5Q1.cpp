#include <iostream>
#include <string>

class Ball
{
	std::string m_colour{};
	double m_radius{};

public:
	Ball(std::string colour = "black", double radius = 10.0)		//Should pass strings by const ref
	{
		m_colour = colour;
		m_radius = radius;
	}

	Ball(double radius)
	{
		m_radius = radius;
		m_colour = "black";
	}

	void print()
	{
		std::cout << "colour: " << m_colour << ", radius: " << m_radius << "\n";
	}
};

int main()					//Main function was provided. Code from here down is copy/pasted.
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}
