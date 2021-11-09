#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{//Animal() 자동 호출
    setType("WrongCat");
    std::cout << "WrongCat default Constructor called\n";
}
WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
{
    std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{//내 대입연산자는 기초클래스 대입연산자를 자동 호출 안 하니 직접 호출
    WrongAnimal::operator=(ref);
    return *this;
}
void WrongCat::makeSound(void) const
{
    std::cout << type << " howled. Myaaaong!\n";
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor called\n";
}