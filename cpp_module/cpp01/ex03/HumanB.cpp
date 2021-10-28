#include "HumanB.hpp"

HumanB::HumanB(std::string s) : mName(s), mWeapon(NULL) {}
//weapon이 객체거나 참조자라면 초기화 필요. 포인터는 안 해도 됨

void HumanB::attack()
{
    std::cout << mName << " attacks with his ";
    if (mWeapon != NULL)
        std::cout << mWeapon->getType() << std::endl;
    else
        std::cout << "bare body\n";
}

void HumanB::setWeapon(Weapon& type)
{
    mWeapon = &type;
}
