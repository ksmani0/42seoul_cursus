#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : mName("default"), mHitPoints(10), mEnergyPoints(10), mAttackDamage(0)
{
    std::cout << "ClapTrap Default Constructor called\n";
}
ClapTrap::ClapTrap(std::string name)
: mName(name), mHitPoints(10), mEnergyPoints(10), mAttackDamage(0)
{
    std::cout << "ClapTrap <" << mName << "> Constructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap& ref) : mName(ref.mName), 
mHitPoints(ref.mHitPoints), mEnergyPoints(ref.mEnergyPoints), mAttackDamage(ref.mAttackDamage)
{
    std::cout << "ClapTrap copy Constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
    mName = ref.mName;
    mHitPoints = ref.mHitPoints;
    mEnergyPoints = ref.mEnergyPoints;
    mAttackDamage = ref.mAttackDamage;
    std::cout << "ClapTrap <" << mName << "operator= called\n";
    return *this;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << "ClapTrap <" << mName << "> attacks <" << target <<
    ">, causing <" << mAttackDamage << "> points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap <" << mName << "> has taken <" << amount <<
    "> of damege\n";

    if (amount >= mEnergyPoints)
    {
        mEnergyPoints = 0;
        std::cout << "ClapTrap <" << mName << "> died\n";
    }
    else
    {
        mEnergyPoints -= amount;
        std::cout << "ClapTrap <" << mName << "> has <" << mEnergyPoints
        << "> energy points left\n";
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap <" << mName <<
    "> has been repaired and has gain <" << amount << "> energy points\n";

    if (amount + mEnergyPoints >= 10)
    {
        mEnergyPoints = 10;
        std::cout << "ClapTrap <" << mName << "> has been completely repaired\n";
    }
    else
    {
        mEnergyPoints += amount;
        std::cout << "ClapTrap <" << mName << "> has <" << mEnergyPoints
        << "> energy points left\n";
    }
}
unsigned int ClapTrap::GetHitPoint(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    return rand() % 11;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap <" << mName << "> Destructor called\n";
}