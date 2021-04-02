#include<iostream>
#include<array>
#include<numeric>

enum Items
{
	item_healthPotion,
	item_torches,
	item_arrows
};

int countTotalItems(const std::array<int, 3> &player1)
{
	return std::reduce(player1.begin(), player1.end());
}

int main()
{
	std::array<int, 3> player1{ 2, 5, 10 };
	int totalItems{ countTotalItems(player1) };
	std::cout << "Player 1 has " << player1[Items::item_torches] << " torches and " << totalItems 
		<< " items in total.\n";

	return 0;
}