#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//Create A,B or C at random and return it as a Base pointer

Base* generate(void)
{
    int n = rand() % 3;

    if(n == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return (new A);
    }
    if (n == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return (new B);
    }
    std::cout << "Generated: C" << std::endl;
    return (new C);
}

//dynamic_cast returns NULL if p is not really that type
void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    //Is it an A?
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...)
    {
        //Not an A, try the next one
    }
    //Is it an B?
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(...)
    {
        //Not a B, try the next one
    }
    //Is it an C?
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(...)
    {
        //Not a C either
    }
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 6; i++)
    {
        Base* p = generate();

        std::cout << "Pointer: ";
        identify(p);
        std::cout << "Reference: ";
        identify(*p);
        std::cout << std::endl;

        delete (p);
    }
    return (0);
}
