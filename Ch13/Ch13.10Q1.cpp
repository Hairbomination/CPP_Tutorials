#include <iostream>
#include <string>

class Mystring
{
private:
    std::string m_string{};

public:
    Mystring(std::string string) : m_string{ string } {}    //Their constructor: Mystring(const std::string& string = {})
                                                            //:m_string{ string }{}
    Mystring() = default;
    
   const std::string operator()(int x, int y) const;    //Nothing should be consted here. I still don't get it.
};                                                      //They also defined the function within the class.

const std::string Mystring::operator()(int x, int y) const
{                                           //They added an assert to make sure the substring would be in range. I have to start doing that
    std::string temp{m_string[x]};      //The extra variable WAS NECESSARY this time!!!
    while (y > 1)                       //They used a for loop: 
    {                                   //std::string ret{};
        temp += m_string[++x];          //for (int count{ 0 }; count < length; ++count)
        --y;                            //{ret += m_string[static_cast<std::string::size_type>(start + count)];}
    }
    return temp;
}

int main()              //Code from here down is copy/paste
{
    Mystring string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}