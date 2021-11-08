#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class ClapTrap
{
    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& ref);

    ClapTrap& operator=(const ClapTrap& ref);

    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    unsigned int GetHitPoint();
   
    ~ClapTrap();

    private:
    std::string mName;
    int mHitPoints;
    int mEnergyPoints;
    int mAttackDamage;
};

#endif