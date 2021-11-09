#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
    AMateria();
    AMateria(const AMateria& ref);
    AMateria(std::string const& type);

    AMateria& operator=(const AMateria& ref);
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);//이것도 순수가상함수가 낫겠다
    virtual std::string GetType() const = 0;
    virtual void SetType(std::string type) = 0;

    virtual ~AMateria();

protected:
    std::string type;
};

#endif