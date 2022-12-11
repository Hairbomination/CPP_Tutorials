#include <iostream>
#include <cstdint> // for fixed width integers
#include <cmath> // for std::round()

class FixedPoint2
{
private:
	std::int16_t m_base{};				//My code is lines 35-63. All else is copy/paste
	std::int8_t m_decimal{};			//I did think about const-ing stuff, but decided not to in case I broke something already working.

public:
	FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0)
		: m_base{ base }, m_decimal{ decimal }
	{
		if (m_base < 0 || m_decimal < 0)
		{
			if (m_base > 0)
				m_base = -m_base;
			if (m_decimal > 0)
				m_decimal = -m_decimal;
		}
	}

	FixedPoint2(double d) :
		m_base{ static_cast<std::int16_t>(std::trunc(d)) },
		m_decimal{ static_cast<std::int8_t>(std::round(d * 100) - m_base * 100) }
	{
	}

	operator double() const
	{
		return m_base + (static_cast<double>(m_decimal) / 100);
	}
	
	friend FixedPoint2 operator+(FixedPoint2 a, FixedPoint2 b);	//They defined this outside the class
	friend bool operator== (FixedPoint2 a, FixedPoint2 b);	//They just wrote the function body below the declaration
	FixedPoint2 operator-();	//Also could've just written the function body here
	friend std::istream& operator>> (std::istream& in, FixedPoint2& a);	//This didn't need to be a friend. It's the same as the ostream.
};			//Why did they bother going through all the friend/member/normal function rules if they never follow them???

FixedPoint2 operator+(FixedPoint2 a, FixedPoint2 b)	//Should have const the parameters
{
	return FixedPoint2{ static_cast<double>(a) + static_cast<double>(b) };
}

bool operator == (FixedPoint2 a, FixedPoint2 b)	//Should have const the parameters.
{
	return (a.m_base == b.m_base && a.m_decimal == b.m_decimal);
}

FixedPoint2 FixedPoint2::operator-()	//Should have const the funtion.
{
	return { -m_base, -m_decimal };		//They said these should be static cast to int16 and int8 because the negative sign
}									//converts narrow integer types to int.

std::istream& operator>> (std::istream& in, FixedPoint2& blah)
{
	double hm{};
	in >> hm;
	blah = FixedPoint2{ hm };	//This took a fair bit of brain power. I eventually figured out that this works because 
								//the function parameter is a reference to blah so it's actually changing the value of the original variable.
	return in;					//so it's not about what value is stored in 'in' or whatever.
}

// This doesn't require access to the internals of the class, so it can be defined outside the class
std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
	out << static_cast<double>(fp);
	return out;
}

void testAddition()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}