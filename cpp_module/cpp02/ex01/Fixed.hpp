#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
    Fixed(void);//기본 생성자
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed& ref);//복사 생성자
    Fixed& operator=(const Fixed& ref);//대입 연산자

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;//고정소수점 -> 부동소수점
    int toInt( void ) const;//고정소수점 -> 정수
    ~Fixed();//소멸자

    private:
    int mFixedPoint;//정수부 비트 24개 | 소수부 비트 8개
    static const int mFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& f);
//<<, >> 연산자 오버로딩은 ostream, istream을 손댈 수 없으니 전역함수 형태

#endif