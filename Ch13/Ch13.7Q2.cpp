#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(const std::string& make, const std::string& model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
    friend bool operator< (const Car& c1, const Car& c2);
    friend std::ostream& operator<<(std::ostream& out, const Car& c1);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
        c1.m_model != c2.m_model);
}

bool operator< (const Car& c1, const Car& c2)       //My code is lines 21, 22, 37-52. All else is copy/paste
{
    if (c1.m_make == c2.m_make)             //Note that this solution requires the overloaded operator== function to be present
    {                                       //Which I didn't think about when I wrote this function, but it's ok cause the overloaded
        return c1.m_model < c2.m_model;     //operator== was included in the copied code.
    }
    else
        return c1.m_make < c2.m_make;
}

std::ostream& operator<<(std::ostream& out, const Car& c1)
{
    out << "(" << c1.m_make << ", " << c1.m_model << ")";

    return out;
}

int main()
{
    std::vector<Car> cars{
      { "Toyota", "Corolla" },
      { "Honda", "Accord" },
      { "Toyota", "Camry" },
      { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}