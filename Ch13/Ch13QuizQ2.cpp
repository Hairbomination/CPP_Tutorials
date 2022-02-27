#include <iostream>		//Forgot to #include <cstdint> for the fixed-width integers. My IDE doesn't seem to care though.

using int32 = std::int_least32_t;		//Using statement not required. They only used these types once and passed ints as parameters.
using int8 = std::int_least8_t;

class Average
{
private:
	int32 m_sum{};
	int8 m_count{};

public:
	Average(int32 sum = 0, int8 count = 0) : m_sum{ sum }, m_count{ count }{}	//They initialised the variables with 0 above, then used a weird default constructor here.
																				//Average(){}. I don't understand the rules. They seem to do it differently each time.
	Average& operator+=(int32 sum);
	friend std::ostream& operator<<(std::ostream& out, const Average& average);
};

Average& Average::operator+=(int32 sum)		//Could've put this inside the class. Parameter could've been a normal int.
{
	m_sum += sum;
	++m_count;
	return *this;		//Took longer than it should've to figure this out. Stoopid *this syntax.
}

std::ostream& operator<<(std::ostream& out, const Average& average)	//This also could've gone inside the class.
{
	out << static_cast<float>(average.m_sum) / static_cast<int>(average.m_count);	//Only the 1st static cast was needed here.
	return out;
}

int main()					//Code from here down is copy/paste
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}