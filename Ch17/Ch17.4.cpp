#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
	const std::string m_name;		//These didn't need to be const
	const std::string m_colour;

public:
	Fruit(const std::string_view name = " ", const std::string_view colour = " ")	//They didn't have any default values
		: m_name{name}, m_colour{colour}		//String_view not needed apparently, but I copied it from one of their examples. They used references to strings
	{
	}

	const std::string& getName() const { return m_name; }
	const std::string& getColour() const { return m_colour; }
};

class Apple : public Fruit
{
private:
	const double m_fibre;		//Didn't need to be const

public:
	Apple(const std::string_view name = " ", const std::string_view colour = " ", const double fibre = 0.0)
		: Fruit{ name, colour }, m_fibre{ fibre }
	{
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Apple& apple)	//They defined the function outside the class and without "friend." I still don't get these rules.
	{
		out << "Apple(" << apple.getName() << ", " << apple.getColour() << ", " << apple.m_fibre << ")"; //They called a getFibre() function here instead of directly accessing the variable

		return out;
	}
};

class Banana : public Fruit
{
public:
	Banana(const std::string_view name = " ", const std::string_view colour = " ") //Could've used references to strings
		: Fruit{ name, colour }
	{
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Banana& banana)
	{
		out << "Banana(" << banana.getName() << ", " << banana.getColour() << ")";

		return out;
	}
};

int main()		//Code from here down is copy/paste.
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
