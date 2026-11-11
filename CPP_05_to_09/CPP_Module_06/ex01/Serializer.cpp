#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy)
{
    *this = copy;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
    (void)copy;
    return (*this);
}

Serializer::~Serializer() {}

// adress in memory(pointer) -> number
uintptr_t Serializer::serialize(Data* ptr)
{
    // reinterpret_cast keeps the exact same bits of the address and just labels them as an integer
    return (reinterpret_cast<uintptr_t>(ptr));
}

//number -> adress in memory(pointer)
Data*   Serializer::deserialize(uintptr_t raw)
{
    // reinterpret_cast labels those same bits as a Data address again, with no checks, so it only works if raw came fromaa real Data*.
    return (reinterpret_cast<Data*>(raw));
}