#include<iostream>
#include<tuple>
#include<functional>
#include<cstdlib>

std::tuple<int, int> getInput()
{
	std::cout << "Enter the first integer: ";
	int x{};
	std::cin >> x;
	std::cout << "Enter the second integer: ";
	int y{};
	std::cin >> y;

	return { x, y };

}

char getOperation()
{
	char z{};
	do
	{
		std::cout << "Input '+', '-', '*' or '/': ";
		std::cin >> z;
	}
	while (z != '+' && z != '-' && z != '*' && z != '/');

	return z;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int division(int x, int y)	//Yeah, I know. The instructions said to do it like this.
{							//I'm assuming it's to keep it simple.
	return x / y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char a)
{
	switch (a)
	{
	case '+':
		return &add;
	case '-':
		return &subtract;
	case '*':
		return &multiply;
	case '/':
		return &division;
	default:
		std::cout << "Unknown.";
		std::exit(0);
	}
}

int main()
{
	auto [x, y] {getInput()};
	char z{ getOperation() };
	ArithmeticFunction calculate{ getArithmeticFunction(z) };
	int result{ calculate(x, y) };
	std::cout << "Equals: " << result << '\n';

	return 0;
}
