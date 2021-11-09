#include "AMateria.hpp"

AMateria::AMateria(void) : type("") {}
AMateria::AMateria(const AMateria& ref) : type(ref.type) {}
AMateria::AMateria(std::string const& type) : type(type) {}

AMateria& AMateria::operator=(const AMateria& ref)
{
    this->type = ref.type;
    return *this;
}
void AMateria::use(ICharacter& target) { (void)target; }

AMateria::~AMateria(void) {}