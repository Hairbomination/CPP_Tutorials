#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint2				//My code is lines 3 and 24-28. All other code is copy/paste 
{
private:
	std::int16_t m_base{};
	std::int8_t m_decimal{};

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

	FixedPoint2(double x)			//I was close. Their code: FixedPoint2(double d) : m_base{ static_cast<std::int16_t>(std::trunc(d)) },
	{								//m_decimal{ static_cast<std::int8_t>(std::round(d * 100) - m_base * 100) } {}
		m_base = static_cast<int16_t>(std::trunc(x));
		m_decimal = static_cast<int8_t>(std::round((x - m_base) * 100));
	}

	operator double() const
	{
		return m_base + (static_cast<double>(m_decimal) / 100);
	}
};


std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
	out << static_cast<double>(fp);
	return out;
}

int main()
{
	FixedPoint2 a{ 0.01 };
	std::cout << a << '\n';

	FixedPoint2 b{-0.01};
	std::cout << b << '\n';

	// Handle cases where the argument has some rounding error
	FixedPoint2 c{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	FixedPoint2 d{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 e{ 106.9978 }; // should be stored with base 107 and decimal 0
	std::cout << e << '\n';

	FixedPoint2 f{ 1.9 }; // make sure we handle single digit decimal
	std::cout << f;

	return 0;
}