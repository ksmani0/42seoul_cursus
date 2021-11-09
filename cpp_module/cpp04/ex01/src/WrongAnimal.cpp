#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type()
{
    std::cout << "WrongAnimal default Constructor called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& ref) : type(ref.type)
{
    std::cout << "WrongAnimal Copy Constructor called\n";
}

std::string WrongAnimal::getType(void) const
{ 
    return type;
}
void WrongAnimal::setType(std::string type)
{
    this->type = type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
    type = ref.type;
    return *this;
}
void WrongAnimal::makeSound(void) const
{
    if (type.length() == 0)
        std::cout << "Some WrongAnimal howled. Krrrrrr!\n";
    else
        std::cout << type << " howled. Krrrrrr!\n";
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor called\n";
}