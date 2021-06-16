#include <iostream>
#include <array>

/* DOES NOT WORK WITH CLANG ON MAC OS X, will work with gnu g++, not g++ linked to clang++ */

#include <numeric> // for std::reduce -- std = c++20 or newer
#include <execution> // for std::execution::par -- parallel execution of summation std = c++ 20 or newer

enum Items
{
	item_healthPotion,
	item_torches,
	item_arrows,
	num_of_allowable_items
};

static constexpr int initial_num_healthpotions{2};
static constexpr int initial_num_torches{5};
static constexpr int initial_num_arrows{10};

using item_array = std::array<int, Items::num_of_allowable_items>;

int countTotalItems(item_array& player1)
{
	return std::reduce(std::execution::par, player1.cbegin(), player1.cend() );
}

int main()
{
	item_array player1{ initial_num_healthpotions, initial_num_torches, initial_num_arrows };
	int totalItems{ countTotalItems(player1) };
	std::cout << "Player 1 has " << player1[Items::item_torches] << " torches and " << totalItems
		<< " items in total.\n";

	return 0;
}