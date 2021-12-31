#include <iostream>

class Fraction
{
private:
	int m_num{};		//Neglected to include a default constuctor or default values
	int m_den{};

public:
	Fraction(int num, int den) : m_num{ num }, m_den{ den }
	{}

	void print()		//Still forgetting to const these member functions
	{
		std::cout << m_num << "/" << m_den << '\n';
	}
	friend Fraction operator*(const Fraction& f1, int x);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(int x, const Fraction& f1);
};

Fraction operator*(const Fraction& f1, int x)
{
	return { (f1.m_num * x), f1.m_den };
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return { {f1.m_num * f2.m_num}, (f1.m_den * f2.m_den) };
}

Fraction operator*(int x, const Fraction& f1)
{
    return { operator*(f1, x) };        //This was deliberate, just to make sure I understood the concept correctly
}                                   	//However, calling another function takes longer than re-typing one line of code.

int main()                  		//Code from here down is copy/paste
{
    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
    f6.print();

    return 0;
}
