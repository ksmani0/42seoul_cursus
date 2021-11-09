#include "Dog.hpp"

Dog::Dog(void)
{//Animal() 자동 호출
    setType("Dog");
    std::cout << "Dog default Constructor called\n";
}
Dog::Dog(const Dog& ref) : Animal(ref)
{
    std::cout << "Dog Copy Constructor called\n";
}

Dog& Dog::operator=(const Dog& ref)
{//내 대입연산자는 기초클래스 대입연산자를 자동 호출 안 하니 직접 호출
    Animal::operator=(ref);
    return *this;
}
void Dog::makeSound(void) const
{
    std::cout << type << " howled. MeongMeong!\n";
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor called\n";
}