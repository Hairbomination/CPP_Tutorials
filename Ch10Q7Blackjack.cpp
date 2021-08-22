#include<iostream>
#include<array>
#include<cstddef>
#include<iterator>
#include<algorithm>
#include<random>
#include<ctime>

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

using array_t = std::array<Card, (static_cast<int>(Rank::max_rank)* static_cast<int>(Suits::max_suits))>;

array_t createDeck(array_t& temp)
{
	std::size_t iterate1{ 0 };

	for (int loop2{ 0 }; loop2 != static_cast<int>(Suits::max_suits); ++loop2)
	{
		for (int loop1{ 0 }; loop1 != static_cast<int>(Rank::max_rank); ++loop1)
		{
			temp[iterate1].rank = static_cast<Rank>(loop1);
			temp[iterate1].suit = static_cast<Suits>(loop2);
			++iterate1;
		}
	}

	return temp;
}

void printCard(const Card& temp)
{
	switch (temp.suit)
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
	switch (temp.rank)
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
}

void printDeck(const array_t& temp)
{
	for (auto iterate1 : temp)
	{
		printCard(iterate1);
		std::cout << " ";
	}
	std::cout << '\n';
}

array_t shuffleDeck(array_t& temp)
{
	static	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(temp.begin(), temp.end(), mt);

	return temp;
}

int getCardValue(const Card& temp)
{
	switch (temp.rank)
	{
	case Rank::two:
		return 2;
	case Rank::three:
		return 3;
	case Rank::four:
		return 4;
	case Rank::five:
		return 5;
	case Rank::six:
		return 6;
	case Rank::seven:
		return 7;
	case Rank::eight:
		return 8;
	case Rank::nine:
		return 9;
	case Rank::ten:
		return 10;
	case Rank::jack:
		return 10;
	case Rank::queen:
		return 10;
	case Rank::king:
		return 10;
	case Rank::ace:
		return 11;
	default: 
		return 0;
	}
}

int dealCard(const array_t& temp)
{
	static std::size_t iterate{ 0 };
	printCard(static_cast<Card>(temp[iterate]));
	int cardValue{ getCardValue(static_cast<Card>(temp[iterate])) };
	++iterate;

	return cardValue;
}

bool playBlackjack(const array_t& temp)
{
	int dealerScore{ 0 };
	int playerScore{ 0 };
	
	std::cout << "Dealer draws: "; 
	dealerScore = dealCard(temp);
	std::cout << ". Dealer's score is: " << dealerScore << '\n';
	
	std::cout << "Player draws: ";
	playerScore = dealCard(temp);
	std::cout << ", ";
	playerScore = playerScore + dealCard(temp);
	std::cout << ". Player's score is: " << playerScore << '\n';
	
	while (playerScore < 21)
	{
		char player{};
		do
		{
			std::cout << "Another card? Y/N: ";
			std::cin >> player;
		} 
		while (player != 'Y' && player != 'N');
		{
			if (player == 'Y')
			{
				std::cout << "Player draws: ";
				playerScore = playerScore + dealCard(temp);
				std::cout << ". Player's score is: " << playerScore << '\n';
			}
			else
			{
				std::cout << "Player stands on: " << playerScore << '\n';
				break;
			}
		}
	}
	if (playerScore > 21)
	{
		std::cout << "You lose. \n";
		return false;
	}
	else if (playerScore == 21)
	{
		std::cout << "Player wins! \n";
		return true;
	}

	while (dealerScore < 17)
	{
		std::cout << "Dealer draws: ";
		dealerScore = dealerScore + dealCard(temp);
		std::cout << ". Dealer's score is " << dealerScore << '\n';
	}
	if (dealerScore > 21)
	{
		std::cout << "Dealer busts. You win! \n";
		return true;
	}
	else if (playerScore <= dealerScore)
	{
		std::cout << "Dealer stands on: " << dealerScore << ". Dealer wins!";
		return false;
	}
	else
	{
		std::cout << "Dealer stands on: " << dealerScore << ". Player wins!";
		return true;
	}
}

int main()
{
	array_t deck;
	createDeck(deck);
//	printDeck(deck);
	shuffleDeck(deck);
	playBlackjack(deck);

	return 0;
}