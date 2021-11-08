#include "Fixed.hpp"

Fixed::Fixed(void) : mFixedPoint(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed& ref)
{
    std::cout << "Copy constructor called\n";
    *this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
    std::cout << "Assignation operation called\n";
    mFixedPoint = ref.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return mFixedPoint;
}
void Fixed::setRawBits(int const raw)
{
    mFixedPoint = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}