#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(const Ice& ref) : AMateria(ref.type) {}

Ice& Ice::operator=(const Ice& ref)
{
    type = ref.type;
    return *this;
}
AMateria* Ice::clone(void) const
{
    AMateria* temp = new Ice();
    return temp;
}
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
std::string Ice::GetType(void) const
{
    return type;
}
void Ice::SetType(std::string type)
{
    this->type = type;
}

Ice::~Ice(void) {}