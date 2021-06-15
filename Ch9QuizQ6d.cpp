#include <algorithm> // for std::shuffle
#include <random> // for std::default_random_engine
#include<iostream> // for std::cout, std::endl
#include<array>
#include<cstddef> // for std::size_t
#include<iterator>
#include <chrono> //system clock, time since epoch, now, count
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

array_t createDeck()
{
	array_t deck;
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
	return deck;
}

/*

--- per instructions ---

missing function printCard(const& Card&)
*/
void printCard(const Card& card){
	std::cout << suit_names[castToInt(card.suit)] << rank_names[castToInt(card.rank)];
}


void printDeck(const array_t& deck)
{
	for (auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << std::endl;
}

void shuffleDeck(array_t& deck )
{
	const static uint seed = std::chrono::system_clock::now().time_since_epoch().count();
	static auto rng = std::default_random_engine { seed };
	std::shuffle(deck.begin(),deck.end(),rng);
}


int getCardValue(const Card& card)
{
	switch( card.rank )
	{
		case Rank::ace:
			return 11;
		case Rank::ten:
		case Rank::jack:
		case Rank::queen:
		case Rank::king:
			return 10;
		default:
			return castToInt(card.rank) + 2;
	}
}

int main()
{
	array_t deck{ createDeck() };
	shuffleDeck(deck);
	printDeck(deck);

	return 0;
}