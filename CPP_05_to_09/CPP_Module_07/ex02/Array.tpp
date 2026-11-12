#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : _data(NULL), _size(0)
{
    *this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
        delete[] _data;
        _size = copy._size;
        _data = new T[_size]();
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = copy._data[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return "index out of bounds";
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfBoundsException();
    return _data[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfBoundsException();
    return _data[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif