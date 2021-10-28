#include "HumanA.hpp"

HumanA::HumanA(std::string s, Weapon& w) : mName(s), mWeapon(w) {}
//Weapon w로 인자 받으면 생성자 소멸 때까지만 살아있는
//임시 변수 w의 참조자를 멤버변수로 갖게 됨. 이건 위험하니 Weapon& w 쓰자

void HumanA::attack()
{
    std::cout << mName << " attacks with his " <<
    mWeapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon& w)
{
	mWeapon = w;
}
