#include "linked_list.hpp"

#include <iostream>
#include <string>

namespace LCode
{
std::string say_hi()
{
    using std::cout, std::cin;
    using std::string, std::getline;

    cout << "Enter your name: ";
    string name;
    getline(cin, name);
    if (name.length() > 0)
    {
        cout << "Hello, " << name << "!\n";
    }
    
    return name;
}
}