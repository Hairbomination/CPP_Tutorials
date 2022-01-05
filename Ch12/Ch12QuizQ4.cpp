#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

constexpr int minimumDealerScore{ 17 };
constexpr int maximumScore{ 21 };

class Card
{
public:
    enum Suit
    {
        club,
        diamond,
        heart,
        spade,
        max_suits
    };
    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,
        max_ranks
    };
private:
    Rank m_rank{};
    Suit m_suit{};

public:
    Card(Rank rank = rank_ace, Suit suit = spade) : m_rank{ rank }, m_suit{ suit }{}    //Could have added default constructor Card() = default
                                                                                    //but I don't think my way is particularly wrong.
    void print() const
    {
        switch (m_rank)
        {
        case Rank::rank_2:      
        case Rank::rank_3:
        case Rank::rank_4:
        case Rank::rank_5:
        case Rank::rank_6:
        case Rank::rank_7:
        case Rank::rank_8:
        case Rank::rank_9:
                                std::cout << value();
                                break;

        case Rank::rank_10:     std::cout << 'T';   break;
        case Rank::rank_jack:   std::cout << 'J';   break;
        case Rank::rank_queen:  std::cout << 'Q';   break;
        case Rank::rank_king:   std::cout << 'K';   break;
        case Rank::rank_ace:    std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;
        }

        switch (m_suit)
        {
        case Suit::club:       std::cout << 'C';   break;
        case Suit::diamond:    std::cout << 'D';   break;
        case Suit::heart:      std::cout << 'H';   break;
        case Suit::spade:      std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
        }
    }
    int value() const
    {
        switch (m_rank)
        {
        case Rank::rank_2:        return 2;
        case Rank::rank_3:        return 3;
        case Rank::rank_4:        return 4;
        case Rank::rank_5:        return 5;
        case Rank::rank_6:        return 6;
        case Rank::rank_7:        return 7;
        case Rank::rank_8:        return 8;
        case Rank::rank_9:        return 9;
        case Rank::rank_10:       
        case Rank::rank_jack:     
        case Rank::rank_queen:    
        case Rank::rank_king:     return 10;
        case Rank::rank_ace:      return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }

};

class Deck
{
public:
    using array_type = std::array<Card, 52>;
    using index_type = array_type::size_type;

private:
    array_type m_deck{};
    index_type m_cardIndex{ 0 };

public:
    Deck()
    {
        index_type card{ 0 };

        for (int suit{ 0 }; suit < static_cast<int>(Card::Suit::max_suits); ++suit) //Card::max_suits would've worked. It's not an enum class so it doesn't have the scoping thing.
        {
            for (int rank{ 0 }; rank < static_cast<int>(Card::Rank::max_ranks); ++rank) //Also didn't need to static_cast to anything. It's not an enum class
            {
                m_deck[card] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
                ++card;
            }
        }
    }
    void print() const
    {
        for (const auto& card : m_deck)
        {
            card.print();
            std::cout << ' ';
        }

        std::cout << '\n';
    }
    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);
        m_cardIndex = 0;
    }
    const Card& dealCard()
    {                                   //Should have included a line: assert(m_cardIndex < m_deck.size());
        return m_deck[m_cardIndex++];
    }
};

class Player
{
private:
    int m_score{};
    int m_cardValue{};                  //This didn't need to be a member variable. A local variable within drawCard would do

public:
    Player()
    {
        m_score = 0;
        m_cardValue = 0;
    }
    int drawCard(Deck& deck)
    {
        m_cardValue = deck.dealCard().value();
        m_score += m_cardValue;

        return m_cardValue;
    }
    int score()     //This function should be const
    {
        return m_score;
    }
    bool isBust()   //Also should be const
    {
        return m_score > maximumScore;
    }
    bool playerWantsHit()
    {
        while (true)
        {
            std::cout << "(h) to hit, or (s) to stand: ";

            char ch{};
            std::cin >> ch;

            switch (ch)
            {
            case 'h':
                return true;
            case 's':
                return false;
            }
        }
    }
};

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)                                 //This could've been a member variable of Player
{
    while (true)
    {
        if (player.score() > maximumScore)              //Should've used if(player.isBust())
        {
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (player.playerWantsHit())
            {
                int cardValue{ player.drawCard(deck) };
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score() << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score() < minimumDealerScore)
    {
        int cardValue{ dealer.drawCard(deck) };
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score() << '\n';

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.score() > maximumScore)                      //If (dealer.isBust())
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(Deck& deck)
{
    Player dealer{};
    dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    std::cout << "You have: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score() > dealer.score());
}

int main()
{
    Deck deck{};

    deck.shuffle();

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}
