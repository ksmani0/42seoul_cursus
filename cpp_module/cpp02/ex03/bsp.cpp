#include "Point.hpp"

/*
삼각형 내부는 아래 세 영역의 교집합. 점 p는 이 교집합 영역에 있어야 함 
1.직선 ab로 나눠지는 두 영역 중 점 c가 속한 영역
2.직선 bc로 나눠지는 두 영역 중 점 a가 속한 영역
3.직선 ca로 나눠지는 두 영역 중 점 b가 속한 영역

위 정리를 식으로 나타내보자. x는 외적
1.(Xb-Xp)(Ya-Yp)-(Xa-Xp)(Yb-Yp) : PB x PA
2.(Xc-Xp)(Yb-Yp)-(Xb-Xp)(Yc-Yp) : PC x PB
3.(Xa-Xp)(Yc-Yp)-(Xc-Xp)(Ya-Yp) : PA x PC

위 세 식의 값이 0을 제외한 양수이거나 음수면 p는 삼각형 내부
세 식 중 1개만 0이면 삼각형 외부, 2개 이상이 0이면 삼각형 변위, 그외는 삼각형 외부
*/
bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Fixed d1, d2, d3;
    //= 연산으로 Fixed(const float floatValue) 호출
    d1 = (b.GetX().toFloat() - p.GetX().toFloat()) * (a.GetY().toFloat() - p.GetY().toFloat()) -
        (a.GetX().toFloat() - p.GetX().toFloat()) * (b.GetY().toFloat() - p.GetY().toFloat());
    d2 = (c.GetX().toFloat() - p.GetX().toFloat()) * (b.GetY().toFloat() - p.GetY().toFloat()) -
        (b.GetX().toFloat() - p.GetX().toFloat()) * (c.GetY().toFloat() - p.GetY().toFloat());
    d3 = (a.GetX().toFloat() - p.GetX().toFloat()) * (c.GetY().toFloat() - p.GetY().toFloat()) -
        (c.GetX().toFloat() - p.GetX().toFloat()) * (a.GetY().toFloat() - p.GetY().toFloat());

    if (d1 > 0 && d2 > 0 && d3 > 0)
        return true;
    else if (d1 < 0 && d2 < 0 && d3 < 0)
        return true;
    return false;
}

/*
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;

    d1 = (b.GetX() - point.GetX()) * (a.GetY() - point.GetY()) -
        (a.GetX() - point.GetX()) * (b.GetY() - point.GetY());
    d2 = (c.GetX() - point.GetX()) * (b.GetY() - point.GetY()) -
        (b.GetX() - point.GetX()) * (c.GetY() - point.GetY());
    d3 = (a.GetX() - point.GetX()) * (c.GetY() - point.GetY()) -
        (c.GetX() - point.GetX()) * (a.GetY() - point.GetY());

    if (d1 > 0 && d2 > 0 && d3 > 0)
        return true;
    else if (d1 < 0 && d2 < 0 && d3 < 0)
        return true;
    return false;
}
*/