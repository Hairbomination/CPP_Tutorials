#include<iostream>
#include<iterator>
#include<utility>

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ std::size(array) };

	for (int iterate{ 0 }; iterate < length; ++iterate)
	{
		int firstIndex{ 0 };
		for (int secondIndex{ 1 }; secondIndex < length; )
		{
			if (array[firstIndex] > array[secondIndex])
			{
				std::swap(array[firstIndex], array[secondIndex]);
			}
			secondIndex = ++firstIndex + 1;
		}
	}
	for (int print{ 0 }; print < length; ++print)
		std::cout << array[print] << " ";

	return 0;
}