#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(const Cure& ref) : AMateria(ref.type) {}

Cure& Cure::operator=(const Cure& ref)
{
    type = ref.type;
    return *this;
}
AMateria* Cure::clone(void) const
{
    AMateria* temp = new Cure();
    return temp;
}
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
std::string Cure::GetType(void) const
{
    return type;
}
void Cure::SetType(std::string type)
{
    this->type = type;
}

Cure::~Cure(void) {}