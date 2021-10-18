#include<iostream>
#include<tuple>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cstddef>
#include<algorithm>
#include<cmath>

std::tuple<int, std::size_t> getNumbers()
{
	std::cout << "Start where? ";		//The program takes this number and uses it as a base to generate
	int x{};
	std::cin >> x;
	std::cout << "How many? ";			//this many square numbers. Then it multiplies the square numbers
	std::size_t y{};					//by a random number between 2 and 4 and asks the user to guess
	std::cin >> y;						//what numbers have been generated (DUMBEST GAME EVER).

	return{ x, y };
}

int getRandomNumber(int min, int max)		//This function generates the random number between 2 and 4
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; 
	
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void getGameValues(int x, std::size_t y, int random, std::vector<long>& array)	//This creates the array from 
{																				//the numbers input by the user (duh)
	for (std::size_t count{0}; count < y; ++count)
	{
		array[count] = (x * x) * random;
		++x;
	}
}

void wrongGuess(std::size_t y, long guess, std::vector<long>& array)	//This function checks an incorrect guess and checks how badly wrong the guess was
{
	while (y > 0)
	{
		const auto closest{ std::min_element(array.begin(), array.end(), 
			[](const auto& a, const auto& b) {return (a < b);	 }) };				//Compares the guess to each number in the array, starting from the smallest
		if (std::abs(guess - *closest) > 4 || std::abs(*closest - guess) > 4)		//if the user's guess was close to one of the generated numbers  
		{																			//the program will provide the correct answer.
			array.erase(closest);													//Not my choice to use min_element here. They told me to.
			--y;					
		}
		else
		{
			std::cout << guess << " is wrong! Try " << *closest << " next time.";
			break;
		}
	}
	if (y == 0)
		std::cout << guess << " is wrong!";		//If the user's guess wasn't close to any number in the array, the program won't provide the right answer.
}

void findGuess(std::size_t y, std::vector<long>& array)
{
	while (y > 0)								//This function takes guesses from the user and finds correct guesses.
	{
		std::cout << "> ";
		long guess{};
		std::cin >> guess;
		auto found{ std::find(array.begin(), array.end(), guess) };
		if (found != array.end())
		{
			array.erase(found);
			--y;
			if (y > 0)
				std::cout << "Nice! " << y << " number (s) left.\n";
			else
				std::cout << "Nice! You found all numbers, good job!";
		}
		else
		{
			wrongGuess(y, guess, array);
			break;
		}
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();											//Not sure why they suggest calling rand() here, and yes, it's throwing a warning.
	auto [x, y] {getNumbers()};								//They said something about a quirk in some compilers, but didn't really elaborate.
	int random{ getRandomNumber(2, 4) };
	std::vector<long> array(y);
	getGameValues(x, y, random, array);
	std::cout << "I generated " << y << " square numbers. Do you know what each number is after multiplying"
		<< " it by " << random << "? \n";
	findGuess(y, array);

	return 0;
}