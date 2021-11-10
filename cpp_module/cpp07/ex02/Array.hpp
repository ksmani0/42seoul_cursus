#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int n);
    Array(const Array& ref);

    Array& operator=(const Array& ref);
    T& operator[](size_t idx);
    size_t size() const;

    class ArrayException : public std::exception
    {
    public:
        ArrayException(std::string m);
        const char* what() const throw();
        ~ArrayException() throw();
    private:
        std::string mMessage;
    };

    ~Array();

private:
    T* mArr;
    size_t mSize;
};

//////////

template <class T>
Array<T>::Array(void) : mArr(NULL), mSize(0) {}

template <class T>
Array<T>::Array(unsigned int n) : mSize(n)
{
    mArr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& ref) : mSize(ref.mSize)
{
    //delete[] mArr; //생성자니까 없어도 됨

    mArr = new T[mSize];
    for (int i = 0; i < mSize; ++i)
    {
        mArr[i] = ref.mArr[i];
    }
}

//////////

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
    delete[] mArr;

    mSize = ref.size();
    mArr = new T[mSize];
    for (int i = 0; i < mSize; ++i)
    {
        mArr[i] = ref.mArr[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t idx)
{
    if (idx >= mSize || idx < 0)
        throw ArrayException("Input index is out of array!");
    return mArr[idx];
}

//////////

template <typename T>
size_t Array<T>::size(void) const
{
    return mSize;
}

template <typename T>
Array<T>::ArrayException::ArrayException(std::string m)
: mMessage(m) {}

template <typename T>
const char* Array<T>::ArrayException::what(void) const throw()
{
    return mMessage.c_str();
}

template <typename T>
Array<T>::ArrayException::~ArrayException(void) throw() {}

//////////

template <typename T>
Array<T>::~Array()
{
    delete[] mArr;
}

#endif