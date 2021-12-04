#include <iostream>
#include <iterator>

/*int binarySearch(const int* array, int target, int min, int max)      //Iterative version
{
    bool found{false};
    while (max >= min && found == false)
    {
        int centre{ min + ((max - min) / 2) };
        if (*(array + centre) > target)
            max = (centre - 1);
        else if (*(array + centre) < target)
            min = (centre + 1);
        else if (*(array + centre) == target)
        {
            found = true;
            return centre;
        }
    }
    return -1;
}*/

int binarySearch(const int* array, int target, int min, int max)      //Recursive version
{
    int centre{ min + ((max - min) / 2) };
    if (max < min)
        return -1;
    else if (array[centre] == target)
        return centre;
    else
    {
        if (array[centre] > target)
            max = (centre - 1);
        else
            min = (centre + 1);
        binarySearch(array, target, min, max);
    }
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    constexpr int numTestValues{ 9 };
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    for (int count{ 0 }; count < numTestValues; ++count)
    {
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}
