#include<iostream>
#include<array>
#include<cstddef>
#include<iterator>

#define whichRank static_cast<Rank>
#define whichSuit static_cast<Suit>
#define castToInt static_cast<std::size_t>

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


static constexpr std::size_t ranks_per_suit = castToInt(Rank::number_of_ranks_in_suit);

static const std::array<std::string, ranks_per_suit> rank_names =  {
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

static constexpr std::size_t suits_per_deck = castToInt(Suit::number_of_suits_in_deck);

static  const std::array<std::string, suits_per_deck> suit_names = {
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
static constexpr std::size_t deck_size =suits_per_deck * ranks_per_suit;

using array_t = std::array<Card, deck_size>;

void createDeck(array_t& deck)
{

	Rank currentRank{ whichRank(0) };
	Suit currentSuit{ whichSuit(0) };

	for (auto& card: deck )
	{
		card.suit = currentSuit;
		card.rank = currentRank;
		currentRank = whichRank(castToInt(currentRank) + 1);
		currentRank = whichRank(castToInt(currentRank) % ranks_per_suit);
		if(currentRank == whichRank(0))
		{
			currentSuit = whichSuit(castToInt(currentSuit) + 1);
			currentSuit = whichSuit(castToInt(currentSuit) % suits_per_deck);
		}
	}
}

void printDeck(const array_t& deck)
{
	for (auto card : deck)
	{
		std::cout << suit_names[castToInt(card.suit)] << rank_names[castToInt(card.rank)] << " ";
	}
}

int main()
{
	array_t deck;
	createDeck(deck);
	printDeck(deck);

	return 0;
}