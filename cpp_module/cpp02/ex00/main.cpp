#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a);//복사 생성자 호출
    Fixed c;
    c = b;//대입 연산자 오버로딩 호출

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}