#include <iostream>
#include <string>
#include "iter.hpp"

//Template function: only reads the element
template <typename T>
void print(const T& x)
{
    std::cout << x << std::endl;
}

//Normal function: changes the element
void addOne(int& x)
{
    x++;
}

int main()
{
    int nums[] = {1, 2, 3};
    const std::string words[] = {"hello", "world"};
    
    std::cout << "numbers: " << std::endl;
    iter(nums, 3, print<int>);

    iter(nums, 3, addOne);

    std::cout << "numbers after addOne: " << std::endl;
    iter(nums, 3, print<int>);

    std::cout << "words: " << std::endl;
    iter(words, 2, print<std::string>);

    return (0);
}