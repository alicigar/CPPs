#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void iter(T* array, const unsigned int length, F function)
{
    for (unsigned int i = 0; i < length; i++)
        function(array[i]);
}

#endif