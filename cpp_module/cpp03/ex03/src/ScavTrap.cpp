#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    SetHitPoint(100);
    SetEnergyPoint(50);
    SetAttackDamage(20);
    std::cout << "ScavTrap Default Constructor called\n";
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    SetHitPoint(100);
    SetEnergyPoint(50);
    SetAttackDamage(20);
    std::cout << "ScavTrap <" << GetName() << "> Constructor called\n";
}
ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref)
{
    std::cout << "ScavTrap <" << GetName() << "> copy Constructor called\n";
}

/////////

ScavTrap& ScavTrap::operator=(ScavTrap const& src)
{
    std::cout << "ScavTrap <" << GetName() << "operator= called\n";
    ClapTrap::operator=(src);
    return *this;
}

/////////

void ScavTrap::attack(std::string const& target)
{
    std::cout << "ScavTrap <" << GetName() << "> attacks <" << target <<
    ">, causing <" << GetAttackDamage() << "> points of damage!\n";
}
void ScavTrap::guardGate(void)
{
    if (GetEnergyPoint() != 0)
        std::cout << "ScavTrap <" << GetName() << "> has entered in Gate keeper mode\n";
    else
        std::cout << "ScavTrap <" << GetName() << "> cannot enter gatekeeper mode\n";
}

/////////

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap <" << GetName() << "> Destructor called\n";
}