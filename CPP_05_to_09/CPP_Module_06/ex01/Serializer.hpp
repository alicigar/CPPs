#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& copy);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data*     deserialize(uintptr_t raw);
};

#endif

//Coges la dirección de memoria de un objeto Data(un puntero)
//La conviertes en un número entero(serialize) y luego conviertes ese número
//otra vez en puntero(deserialize). Al final compruebas que el puntero que vuelve
//es el mismo que el de partida.