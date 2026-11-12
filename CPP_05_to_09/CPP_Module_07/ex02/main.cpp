#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    // 1. Empty array
    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;

    // 2. Array of n elements, default values (ints start at 0)
    Array<int> a(3);
    std::cout << "a size: " << a.size() << std::endl;
    std::cout << "default values: " << a[0] << " " << a[1] << " " << a[2] << std::endl;

    // 3. Write through []
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    std::cout << "a: " << a[0] << " " << a[1] << " " << a[2] << std::endl;

    // 4. Copy constructor: changing the copy must not change the original
    Array<int> b(a);
    b[0] = 99;
    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

    // 5. Assignment: changing the original must not change the copy
    Array<int> c;
    c = a;
    a[1] = 77;
    std::cout << "a[1] = " << a[1] << ", c[1] = " << c[1] << std::endl;

    // 6. Out of bounds must throw
    try
    {
        a[3] = 1;
    }
    catch (const std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    // 7. Const array (uses the const operator[])
    const Array<int> k(a);
    std::cout << "const k[2] = " << k[2] << std::endl;

    // 8. Another type: strings
    Array<std::string> s(2);
    s[0] = "hello";
    s[1] = "world";
    std::cout << "strings: " << s[0] << " " << s[1] << std::endl;

    return 0;
}