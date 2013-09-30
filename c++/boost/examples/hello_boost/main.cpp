#include <iostream>
#include <boost/array.hpp>

int main(void)
{
    boost::array<std::string, 2> strArray = { "Hello", "World!" };
    boost::array<std::string, 2>::iterator it;

    for (it = strArray.begin(); it != strArray.end(); ++it)
    {
        // if the iterator is just before the end, print the iterator
        // value and a newline
        if (it + 1 == strArray.end())
        {
            std::cout << *it << std::endl;
        }
        // otherwise, print the iterator value and a space
        else
        {
            std::cout << *it << " ";
        }
    }

    return 0;
}
