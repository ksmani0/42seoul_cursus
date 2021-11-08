#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    SetHitPoint(100);
    SetEnergyPoint(100);
    SetAttackDamage(30);
    std::cout << "FragTrap Default Constructor called\n";
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    SetHitPoint(100);
    SetEnergyPoint(100);
    SetAttackDamage(30);
    std::cout << "FragTrap <" << GetName() << "> Constructor called\n";
}
FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref)
{
    std::cout << "FragTrap <" << GetName() << "> copy Constructor called\n";
}

//////////

FragTrap& FragTrap::operator=(FragTrap const& src)
{
    std::cout << "FragTrap <" << GetName() << "operator= called\n";
    ClapTrap::operator=(src);//디폴트 대입 연산자가 아니면 내가 직접 호출해야 함
    return *this;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap <" << GetName() << "> wants a high-five\n" << std::endl;
}

//////////

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap <" << GetName() << "> Destructor called\n";
}