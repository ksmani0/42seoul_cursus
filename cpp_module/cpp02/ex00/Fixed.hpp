#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
    Fixed(void);//기본 생성자
    Fixed(const Fixed& ref);//복사 생성자
    Fixed& operator=(const Fixed& ref);//대입 연산자

    int getRawBits(void) const;
    void setRawBits(int const raw);
    ~Fixed();//소멸자

    private:
    int mFixedPoint;
    static const int mConstInt = 8;
};

#endif