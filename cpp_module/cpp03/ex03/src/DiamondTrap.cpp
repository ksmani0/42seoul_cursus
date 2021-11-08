#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
    mName = "default";
    SetName(mName + "_clap_name");
    SetHitPoint(100);
	SetEnergyPoint(50);
	SetAttackDamage(30);
}
DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap()
{
    mName = name;
    SetName(name + "_clap_name");
    SetHitPoint(100);
	SetEnergyPoint(50);
	SetAttackDamage(30);
}
DiamondTrap::DiamondTrap(const DiamondTrap& ref)
: ClapTrap(ref), mName(ref.mName) {}

//////////

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src)
{
    mName = src.mName;
    ClapTrap::operator=(src);//디폴트 대입 연산자가 아니면 내가 직접 호출해야 함
    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name is <" << mName
    << "> and ClapTrap name is <" << GetName() << ">\n";
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

//////////

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap <" << GetName() << "> Destructor called\n";
}