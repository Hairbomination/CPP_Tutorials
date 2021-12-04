#include <iostream>			//At least I remembered not to create any unecessary variables!
#include <cmath>			//For my next trick I'll remember to const the things that should be const-ed

class Point2d
{
private:
	double m_x{};
	double m_y{};

public:

	Point2d(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y }
	{
	}

	void print()			//void print() const
	{
		std::cout << "Point2d:(" << m_x << ", " << m_y << ")\n";
	}

	friend double distanceFrom(Point2d& point1, Point2d& point2);
};

double distanceFrom(Point2d& point1, Point2d& point2)			//Sigh. The function paramaters should be const
{
	return { std::sqrt((point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) +
		(point1.m_y - point2.m_y) * (point1.m_y - point2.m_y)) };			//Didn't need the {}
}


int main()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

	return 0;
}
