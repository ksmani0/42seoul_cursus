#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& ref);

    ClapTrap& operator=(const ClapTrap& ref);

    std::string GetName() const;
    unsigned int GetHitPoint() const;
    unsigned int GetEnergyPoint() const;
    unsigned int GetAttackDamage() const;
    void SetName(std::string name);
    void SetHitPoint(unsigned int point);
    void SetEnergyPoint(unsigned int name);
    void SetAttackDamage(unsigned int name);

    virtual void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
   
    virtual ~ClapTrap();

    private:
    std::string mName;
    int mHitPoints;
    int mEnergyPoints;
    int mAttackDamage;
};

#endif