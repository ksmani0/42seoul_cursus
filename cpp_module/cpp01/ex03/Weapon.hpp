#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
    Weapon(std::string s);
    const std::string& getType();
    void setType(std::string s);

    private:
    std::string mType;
};

#endif