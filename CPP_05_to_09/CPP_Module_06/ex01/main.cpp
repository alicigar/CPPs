#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "hello";

    Data wrong;
    wrong.id = 7;
    wrong.name = "wrong";

    uintptr_t raw = Serializer::serialize(&data);
    Data* back = Serializer::deserialize(raw);

    if (back == &data )
        std::cout << "OK: same pointer" << std::endl;
    else
        std::cout << "KO: different pointer" << std::endl;
    std::cout << back->id << ", " << back->name << std::endl;

    if (back == &wrong )
        std::cout << "OK: same pointer as wrong" << std::endl;
    else
        std::cout << "KO: different pointer from wrong" << std::endl;
    
    std::cout << back->id << ", " << back->name << std::endl;

    return (0);
}