#include "Weapon.hpp"

Weapon::Weapon(std::string s) : mType(s) {}

const std::string& Weapon::getType()
{
    return mType;
}

void Weapon::setType(std::string s)
{
    mType = s;
}