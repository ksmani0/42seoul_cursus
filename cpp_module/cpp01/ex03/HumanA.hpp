#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    std::string mName;
    Weapon& mWeapon;

public:
    HumanA(std::string s, Weapon& w);
    void attack();
	void setWeapon(Weapon& w);
};

#endif
