#include <iostream>
#include <cstdint>

class FixedPoint2
{
private:
	std::int8_t m_fraction{ 0 };	//They initialised the variables in the constructor.
	std::int16_t m_number{ 0 };

public:
	FixedPoint2(std::int16_t number, std::int8_t fraction) : m_number{ number }, m_fraction{ fraction } {}

	double createNum(FixedPoint2 temp);

	friend std::ostream& operator<<(std::ostream& out, FixedPoint2 bob)
	{
		double num{ bob.createNum(bob) };	//Thanks StackOverflow, but how the fuck does this work???
		out << num;		//Theirs was out << static_cast<double>(bob) which I think just calls the overloaded double operator
						//Oh look I created an unnecessary variable again.
		return out;
	}

	operator double() { return static_cast<double>(m_fraction) / 100; }	//Theirs was return m_number + static_cast<double>(m_fraction) / 100;
};

double FixedPoint2::createNum(FixedPoint2 temp)
{
	double num{};

	if (temp.m_number < 0 || temp.m_fraction < 0)
	{
		if (temp.m_number < 0)			//They did this in the constructor, making this whole function unnecessary.
			temp.m_number = -temp.m_number;		//Instead, their calculations was if either number is negative, turn the other number negative too, then they can be added together
		if (temp.m_fraction < 0)
			temp.m_fraction = -temp.m_fraction;
		num = -(temp.m_number + (static_cast<double>(temp.m_fraction) / 100));
		return num;
	}
	else
		num = temp.m_number + (static_cast<double>(temp.m_fraction) / 100);	
	return num;

}

int main()			//Code from here down is copy/paste
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';

	FixedPoint2 b{ -2, 8 };
	std::cout << b << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << c << '\n';

	FixedPoint2 d{ -2, -8 };
	std::cout << d << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

	return 0;
}

