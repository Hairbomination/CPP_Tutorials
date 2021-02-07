#include<iostream>
#include<iterator>

int getValue()
{
	while (true)
	{
		std::cout << "Enter a number between 1 and 9: ";
		int x{};
		std::cin >> x;
		
		switch (x)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			return x;
		default:
		{
			std::cin.ignore(32767, '\n');
			std::cout << "That input is invalid, please try again.\n";
		}
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	}
	}

int searchArray(const int array[], int x)
{
	int countTwo{ 0 };
	while (!(array[countTwo] == x))
		++countTwo;
	
	return countTwo;
}

int main()
{
	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	constexpr int numNumbers{ std::size(array) };
	int x{ getValue() };
	for (int count{ 0 }; count < numNumbers; ++count)
	{
		std::cout << array[count] << " ";
	}
	int y{ searchArray(array, x) };
	std::cout << "\nYou entered the value at index: " << y;
	
	return 0;
}