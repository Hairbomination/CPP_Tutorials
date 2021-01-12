#include <iostream>
#include "constants.h"

void calculateHeight(double initialHeight)
{
    int seconds = 0;
    double heightNow{initialHeight};

    while (heightNow > 0.0)
    {
        std::cout << "At " << seconds << " seconds, the ball is at height: " << heightNow << "\n";
        ++seconds;
        heightNow = initialHeight - (myConstants::gravity * seconds * seconds / 2);
    }
    std::cout << "The ball is on the ground.";
}

int main()
{
    using namespace std;
    cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    cin >> initialHeight;

    calculateHeight(initialHeight);
    
    return 0;
}