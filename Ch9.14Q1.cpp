#include <iostream>
#include <cstddef>
#include <algorithm>
#include <string>
#include <limits>

int main()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t length{};
    std::cin >> length;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string* array{ new std::string[length] {} };
   
   for (std::size_t iterate{ 0 }; iterate < length; ++iterate)
    {
        std::cout << "Enter name #" << iterate + 1 << ": ";
        std::getline(std::cin, array[iterate]);
    }
  
   std::sort(array, array + length);
   std::cout << "Here is your sorted list: \n";
   
   for (std::size_t iterateTwo{ 0 }; iterateTwo < length; ++iterateTwo)
   {
       std::cout << "Name #" << iterateTwo + 1 << ": " << array[iterateTwo] << '\n';
   }
   delete[] array;

    return 0;
}