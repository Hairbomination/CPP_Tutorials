#include<iostream>

void sumDigits(long x)		//My solution
{
	static int y{0};
	if (x < 10)
		std::cout << y + x;
	else
	{
		y = y + (x % 10);
		sumDigits(x / 10);
	}
}

int main()
{
	sumDigits(93427);
	
	return 0;
}


/*int sumNumbers(int x)		//Their solution
{
	if (x < 10)
		return x;
	else
		return sumNumbers(x / 10) + x % 10;
}

int main()
{
	std::cout << sumNumbers(93427);
}*/
