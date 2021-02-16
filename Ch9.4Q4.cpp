#include <cstddef>
#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr std::size_t length{ std::size(array) };

    for (std::size_t iteration{ 0 }; iteration < length - 1; ++iteration)
    {
        static std::size_t lengthTwo{length - 1};
        bool check{ 0 };
        for (std::size_t currentIndex{ 0 }; currentIndex < lengthTwo; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                check = 1;
            }
        }
        --lengthTwo;
        if (check == 0)
        {
            std::cout << "Early termination on iteration " << iteration + 1 << '\n';
            break;
        }
    }
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';

    return 0;
}