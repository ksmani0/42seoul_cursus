#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{//인터페이스 상속
public:
    std::string mName;
	AMateria* mInventory[4];//추상클래스이므로 포인터 써야 함

    Character();
    Character(std::string name);
    Character(const Character& ref);

    Character& operator=(const Character& ref);
    virtual std::string const& getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    virtual ~Character();
};

#endif