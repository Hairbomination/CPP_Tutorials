#include <iostream>

int main()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        {
            int counter{ 5 - outer };
            while (counter >= 1)
            {
                std::cout << "  ";
                --counter;
            }
        }
        {
            int inner{ outer };
            while (inner >= 1)
            {
                std::cout << inner-- << ' ';
            }
        }
        std::cout << '\n';
        ++outer;
    }

    return 0;
}