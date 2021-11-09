#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{//인터페이스인 셈
public:
    virtual std::string const& getName() const = 0;//멤버변수가 없고
    virtual void equip(AMateria* m) = 0;//모든 멤버함수가 순수가상함수면
    virtual void unequip(int idx) = 0;//그 클래스는 인터페이스
    virtual void use(int idx, ICharacter& target) = 0;

    virtual ~ICharacter() {};
};

#endif