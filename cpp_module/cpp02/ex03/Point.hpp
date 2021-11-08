#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    public:
    Point();
    Point(const Point& ref);
    Point(const float f1, const float f2);

    Point& operator=(const Point& ref);

    Fixed GetX() const;
    Fixed GetY() const;

    ~Point();

    private:
    const Fixed mX;
    const Fixed mY;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif