#include "Point.hpp"

Point::Point(void) : mX(0), mY(0) {}
Point::Point(const Point& ref) : mX(ref.mX), mY(ref.mY) {}
Point::Point(const float f1, const float f2) : mX(f1), mY(f2) {}

Point& Point::operator=(const Point& ref)
{
    (Fixed)mX = (Fixed)ref.mX;
    (Fixed)mY = (Fixed)ref.mY;
    return *this;
}

Fixed Point::GetX(void) const
{
    return mX;
}
Fixed Point::GetY(void) const
{
    return mY;
}

Point::~Point(void) {}