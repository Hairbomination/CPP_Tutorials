#include<iostream>

struct Advertising
{
	long countAds;
	float percentAdsClicked;
	float earnPerClick;
};

void calculateEarnings(Advertising moneyEarned)
{
	std::cout << "The number of ads shown today was: " << moneyEarned.countAds << '\n' <<
		"The percentage of ads clicked was: " << moneyEarned.percentAdsClicked << '\n' <<
		"The amount earned per click was: $" << moneyEarned.earnPerClick << '\n' <<
		"You made $" << moneyEarned.countAds * moneyEarned.percentAdsClicked * moneyEarned.earnPerClick << " today.";
};

int main()
{
	std::cout << "Enter the number of ads shown today: ";
	long x{};
	std::cin >> x;
	std::cout << "Enter the percentage of ads clicked by users (in decimal form): ";
	float y{};
	std::cin >> y;
	std::cout << "Enter the amount of money earned per click (dollars and cents): $";
	float z{};
	std::cin >> z;
	Advertising moneyEarned{ x, y, z };
	calculateEarnings(moneyEarned);

	return 0;
}
