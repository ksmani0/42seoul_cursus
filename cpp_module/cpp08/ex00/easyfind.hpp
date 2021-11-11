#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class EasyfindException : public std::exception
{
public:
    EasyfindException(std::string m) : mMessage(m) {}
    const char* what() const throw() { return mMessage.c_str(); }
    ~EasyfindException(void) throw() {}
private:
    std::string mMessage;
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{//typename 안 쓰면 오류남
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw EasyfindException("Value that does not exist in this container!");
    return iter;
}

#endif