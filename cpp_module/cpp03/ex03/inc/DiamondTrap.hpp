#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{//두 클래스가 맨 기초 클래스를 가상으로 상속, 기초 클래스 멤버들을 하나씩만 가짐
    public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& ref);

    DiamondTrap& operator=(DiamondTrap const& src);
    void whoAmI();
    void attack(const std::string& target);
    using FragTrap::highFivesGuys;
    using ScavTrap::guardGate;
    //attack()을 위에 별도 선언했지만 Scavtrap::attack()을 using 없이도 쓸 수 있음
    //DiamondTrap 클래스의 기초 클래스에 속한 멤버함수니까 

    ~DiamondTrap();

    private:
    std::string mName;
};

#endif