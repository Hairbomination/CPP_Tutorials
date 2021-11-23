#include <iostream>
#include <cstdint>

class RGBA
{
	using bob = std::uint_fast8_t;	//Make the using statement public

	bob m_red{};
	bob m_green{};
	bob m_blue{};
	bob m_alpha{};

public:
	RGBA(bob red = 0, bob green = 0, bob blue = 0, bob alpha = 255)
		: m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{
	}
	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) 
			<< " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha);
	}
};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}