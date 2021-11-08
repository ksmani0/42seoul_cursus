#include "Fixed.hpp"

Fixed::Fixed(void) : mFixedPoint(0) {}
Fixed::Fixed(const int intValue)
{
    mFixedPoint = intValue << mFractionalBits;
}//소수 비트로 8비트는 고정이니 8비트만큼 밀어서 공간 확보 
Fixed::Fixed(const float floatValue)
{
    mFixedPoint = (int)roundf(floatValue * (1 << mFractionalBits));
}//부동소수점은 비트 연산 불가. 8비트 소수부에서 부동소수점 값을 고정소수점으로 바꾸는 공식
Fixed::Fixed(const Fixed& ref)
{
    *this = ref;
}

//////////

Fixed& Fixed::operator=(const Fixed& ref)
{
    mFixedPoint = ref.mFixedPoint;
    return *this;
}

bool Fixed::operator>(const Fixed& ref) const
{
    return (mFixedPoint > ref.mFixedPoint);
}
bool Fixed::operator<(const Fixed& ref) const
{
    return (mFixedPoint < ref.mFixedPoint);
}
bool Fixed::operator>=(const Fixed& ref) const
{
    return (mFixedPoint >= ref.mFixedPoint);
}
bool Fixed::operator<=(const Fixed& ref) const
{
    return (mFixedPoint <= ref.mFixedPoint);
}
bool Fixed::operator==(const Fixed& ref) const
{
    return (mFixedPoint == ref.mFixedPoint);
}
bool Fixed::operator!=(const Fixed& ref) const
{
    return (mFixedPoint != ref.mFixedPoint);
}

Fixed Fixed::operator+(const Fixed& ref) const
{
    return Fixed(mFixedPoint + ref.mFixedPoint);
}
Fixed Fixed::operator-(const Fixed& ref) const
{
    return Fixed(mFixedPoint - ref.mFixedPoint);
}
Fixed Fixed::operator*(const Fixed& ref) const
{
    return Fixed(toFloat() * ref.toFloat());
}
Fixed Fixed::operator/(const Fixed& ref) const
{
    return Fixed(toFloat() / ref.toFloat());
}

Fixed& Fixed::operator++(void)
{
    mFixedPoint = mFixedPoint + 1;
    return *this;
}//전위
Fixed& Fixed::operator--(void)
{
    mFixedPoint = mFixedPoint - 1;
    return *this;
}
const Fixed Fixed::operator++(int)
{
    Fixed temp(*this);//temp(mFixedPoint);는 Fixed(const int intValue) 호출
    mFixedPoint = mFixedPoint + 1;//++(*this);
    return temp;
}
const Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    mFixedPoint = mFixedPoint - 1;
    return temp;
}

//////////

int Fixed::getRawBits(void) const
{
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

Fixed& Fixed::min(Fixed& fPoint1, Fixed& fPoint2)
{
    return fPoint1.mFixedPoint <= fPoint2.mFixedPoint ?
    fPoint1 : fPoint2;
}
const Fixed& Fixed::min(const Fixed& fPoint1, const Fixed& fPoint2)
{
    return fPoint1.mFixedPoint <= fPoint2.mFixedPoint ?
    fPoint1 : fPoint2;
}
Fixed& Fixed::max(Fixed& fPoint1, Fixed& fPoint2)
{
    return fPoint1.mFixedPoint >= fPoint2.mFixedPoint ?
    fPoint1 : fPoint2;
}
const Fixed& Fixed::max(const Fixed& fPoint1, const Fixed& fPoint2)
{
    return fPoint1.mFixedPoint >= fPoint2.mFixedPoint ?
    fPoint1 : fPoint2;
}

Fixed::~Fixed(void) {}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{//고정소수점 값을 부동소수점 값으로 바꿔 출력
    o << f.toFloat();
    return o;
}
