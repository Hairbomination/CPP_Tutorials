#include <iostream>
#include <numeric>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
	friend std::istream& operator>>(std::istream& in, Fraction& f);

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)		//My code is lines 54-67. All else is copy/paste
{
	out << f.m_numerator << "/" << f.m_denominator << ' ';

	return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
	in >> f.m_numerator;				//Nope, again
	in >> f.m_denominator;				//Should have added in.ignore(std::numeric_limits<std::streamsize>::max(), '/'); to ignore the separator
										//And call f.reduce() at the end because we're entering a new fraction.
	return in;
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}