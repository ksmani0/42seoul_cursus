#include "Cat.hpp"

Cat::Cat(void)
{//Animal() 자동 호출
    setType("Cat");
    std::cout << "Cat default Constructor called\n";
}
Cat::Cat(const Cat& ref) : Animal(ref)
{
    std::cout << "Cat Copy Constructor called\n";
}

Cat& Cat::operator=(const Cat& ref)
{//내 대입연산자는 기초클래스 대입연산자를 자동 호출 안 하니 직접 호출
    Animal::operator=(ref);
    return *this;
}
void Cat::makeSound(void) const
{
    std::cout << type << " howled. Myaaaong!\n";
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor called\n";
}