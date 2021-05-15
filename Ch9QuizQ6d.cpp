#include<iostream>
#include<array>
#include<cstddef>
#include<iterator>

enum class Rank
{
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,
	max_rank
};

enum class Suits
{
	hearts,
	diamonds,
	spades,
	clubs,
	max_suits
};

struct Card
{
	Rank rank{};
	Suits suit{};
};

using array_t = std::array<Card, (static_cast<int>(Rank::max_rank)*static_cast<int>(Suits::max_suits))>;

array_t createDeck(array_t& temp)
{
	std::size_t arraysize{ std::size(temp) };
	
	for (std::size_t iterate1{ 0 }; iterate1 != arraysize; )
	{
		for (int loop2{ 0 }; loop2 != static_cast<int>(Suits::max_suits);)
		{
			for (int loop1{ 0 }; loop1 != static_cast<int>(Rank::max_rank); ++loop1)
			{
				temp[iterate1].rank = static_cast<Rank>(loop1);
				temp[iterate1].suit = static_cast<Suits>(loop2);
				++iterate1;
			}
			++loop2;
		}
	}
	
	return temp;
}

void printDeck(const array_t& temp)
{
	for (auto iterate2 : temp)
	{
		switch (iterate2.suit)
		{
		case  Suits::hearts:
			std::cout << "H";
			break;
		case Suits::diamonds:
			std::cout << "D";
			break;
		case Suits::spades:
			std::cout << "S";
			break;
		case Suits::clubs:
			std::cout << "C";
		}
		switch (iterate2.rank)
		{
		case Rank::two:
			std::cout << "2";
			break;
		case Rank::three:
			std::cout << "3";
			break;
		case Rank::four:
			std::cout << "4";
			break;
		case Rank::five:
			std::cout << "5";
			break;
		case Rank::six:
			std::cout << "6";
			break;
		case Rank::seven:
			std::cout << "7";
			break;
		case Rank::eight:
			std::cout << "8";
			break;
		case Rank::nine:
			std::cout << "9";
			break;
		case Rank::ten:
			std::cout << "T";
			break;
		case Rank::jack:
			std::cout << "J";
			break;
		case Rank::queen:
			std::cout << "Q";
			break;
		case Rank::king:
			std::cout << "K";
			break;
		case Rank::ace:
			std::cout << "1";
		}
		std::cout << " ";
	}
}

int main()
{
	array_t deck;
	createDeck(deck);
	printDeck(deck);

	return 0;
}