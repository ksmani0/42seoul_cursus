#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{//부모를 가상 상속한 자식 클래스를 여러 개 상속한 손자 클래스는 부모 클래스 멤버들을 하나씩만 가질 수 있음
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& ref);

    FragTrap& operator=(FragTrap const& src);
    void highFivesGuys(void);

    ~FragTrap();
};

#endif