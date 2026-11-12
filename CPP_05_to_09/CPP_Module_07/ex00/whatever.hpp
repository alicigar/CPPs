#ifndef WHATEVER_HPP
# define WHATEVER_HPP

//swap the values of a and b
template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

//Return the smallest. If equal, return the second one
template <typename T>
const T& min(const T& a, const T& b)
{
    if (a < b)
        return (a);
    return (b);
}

//Return the greatest. If equal, return the second one
template <typename T>
const T& max(const T& a, const T& b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif