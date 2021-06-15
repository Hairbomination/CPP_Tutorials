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
	number_of_ranks_in_suit
};

static const std::array<std::string, static_cast<int>(Rank::number_of_ranks_in_suit)> rank_names =  {
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"T",
	"J",
	"Q",
	"K",
	"1"	
};

enum class Suit
{
	hearts,
	diamonds,
	spades,
	clubs,
	number_of_suits_in_deck
};

static  const std::array<std::string, static_cast<int>(Suit::number_of_suits_in_deck)> suit_names = {
	"H", //Hearts
	"D", //Diamonds
	"S", //Spades
	"C" //Clubs
};

struct Card
{
	Rank rank{};
	Suit suit{};
};
static constexpr std::size_t deck_size = static_cast<std::size_t>(Rank::number_of_ranks_in_suit)*static_cast<std::size_t>(Suit::number_of_suits_in_deck);

using array_t = std::array<Card, deck_size>;

void createDeck(array_t& deck)
{

	Rank currentRank{static_cast<Rank>(0)};
	Suit currentSuit{static_cast<Suit>(0)};

	for (auto& card: deck )
	{
		card.suit = currentSuit;
		card.rank = currentRank;
		currentRank = static_cast<Rank>(static_cast<int>(currentRank) + 1);
		currentRank = static_cast<Rank>(static_cast<int>(currentRank) % 13);
		if(currentRank == static_cast<Rank>(0))
		{
			currentSuit = static_cast<Suit>(static_cast<int>(currentSuit) + 1);
			currentSuit = static_cast<Suit>(static_cast<int>(currentSuit) % 4);
		}
	}
}

void printDeck(const array_t& deck)
{
	for (auto card : deck)
	{
		std::cout << suit_names[static_cast<std::size_t>(card.suit)] << rank_names[static_cast<std::size_t>(card.rank)] << " ";
	}
}

int main()
{
	array_t deck;
	createDeck(deck);
	printDeck(deck);

	return 0;
}