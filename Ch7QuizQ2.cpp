#include <iostream>
#include <cassert>

/*bool isPrime(int x)       This was the solution that I first wrote with without cheating.
{                           Leaving it here so that I can wallow in shame for creating such ugly code.
    if (x == 0 || x == 1)
        return (0);
    if (x == 2)
        return (1);
    {
        int prime{};
        for (int count{ x - 1 }; count > 1; --count)
        {
            prime = x % count;
            if (prime == 0)
                break;      Just needed a return statement here. I think the return statement is a break.
        }
        if (prime == 0)
            return (0);
        else
            return (1);
    }
}
*/
                        //A better solution after I looked up other ppl's answers.
bool isPrime(int x)     //I was SO CLOSE to this at some point. I think I got the return statements in the wrong block or something. ARGH!
{                       //oh yeah. And I think I left out the if statement. That's probably why it didn't work.
    if (x == 0 || x == 1)
        return (0);
    {
        for (int count{2}; count < x; ++count)  //Don't need to worry about x = 2. It'll skip the loop and return true anyway.
        {
            if(x % count == 0)
                return (0);
        }
        return (1);
    }
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!";

    return 0;
}