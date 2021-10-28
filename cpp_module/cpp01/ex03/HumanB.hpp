#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string mName;
    Weapon* mWeapon;

public:
    HumanB(std::string s);
    void attack();
    void setWeapon(Weapon& type);
};

#endif
