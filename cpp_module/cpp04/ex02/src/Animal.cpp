#include "Animal.hpp"

Animal::Animal(void) : type()
{
    std::cout << "Animal default Constructor called\n";
}
Animal::Animal(const Animal& ref) : type(ref.type)
{
    std::cout << "Animal Copy Constructor called\n";
}

std::string Animal::getType(void) const
{ 
    return type;
}
void Animal::setType(std::string type)
{
    this->type = type;
}
Animal& Animal::operator=(const Animal& ref)
{
    type = ref.type;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << "Animal Destructor called\n";
}

/*
void Animal::makeSound(void) const
{
    if (type.length() == 0)
        std::cout << "Some animal howled. Kaaang!\n";
    else
        std::cout << type << " howled. Kaaang!\n";
}
*/