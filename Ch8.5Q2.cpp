#include<iostream>

struct Fractions
{
	int numerator;
	int denominator;
};

Fractions getInput()
{
	Fractions temp;
	std::cout << "Enter the numerator: ";
	std::cin >> temp.numerator;
	std::cout << "Enter the denominator: ";
	std::cin >> temp.denominator;

	return temp;
}

float multiply(Fractions one, Fractions two)
{
	float x = (static_cast<float>(one.numerator) / one.denominator) * (static_cast<float>(two.numerator) / two.denominator);

	return x;
}

int main()
{
	Fractions one{ getInput() };
	Fractions two{ getInput() };
	float result{ multiply(one, two) };
	std::cout << one.numerator << "/" << one.denominator << " * " << two.numerator << "/" <<
		two.denominator << " = " << result << '\n';

	return 0;
}