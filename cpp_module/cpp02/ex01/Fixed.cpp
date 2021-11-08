#include "Fixed.hpp"

Fixed::Fixed(void) : mFixedPoint(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called\n";
    mFixedPoint = intValue << mFractionalBits;
}//소수 비트로 8비트는 고정이니 8비트만큼 밀어서 공간 확보 
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called\n";
    mFixedPoint = (int)roundf(floatValue * (1 << mFractionalBits));
}//부동소수점은 비트 연산 불가. 8비트 소수부에서 부동소수점 값을 고정소수점으로 바꾸는 공식
Fixed::Fixed(const Fixed& ref)
{
    std::cout << "Copy constructor called\n";
    *this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
    std::cout << "Assignation operation called\n";
    mFixedPoint = ref.mFixedPoint;
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

float Fixed::toFloat( void ) const
{//고정소수점 값을 부동소수점 값으로 바꿈
    return (float)mFixedPoint / (1 << mFractionalBits);
}//고정소수점을 float로 강제 형변환해 부동소수점으로 변환하고 고정소수점의 Fractional Bits를 표현하기 위해 << 연산한 값을 되돌리기
int Fixed::toInt( void ) const
{//고정소수점 값을 정수로 바꿈
    return mFixedPoint >> 8;
}//8비트만큼 당겨서 소수부 덮어버리고 출력

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{//고정소수점 값을 부동소수점 값으로 바꿔 출력
    o << f.toFloat();
    return o;
}