#include <iostream>

int main()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        int inner{ 5 };
        while (inner >= outer)
        {
            std::cout << inner-outer+1 << ' ';
            --inner;
        }
        std::cout << '\n';
        ++outer;
    }

    return 0;
}