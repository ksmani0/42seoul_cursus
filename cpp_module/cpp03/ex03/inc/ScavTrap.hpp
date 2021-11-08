#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& ref);

    ScavTrap& operator=(ScavTrap const& src);
    void attack(std::string const & target);
    //virtual 안 달아도 부모한테 달렸으면 안 달아도 됨
    void guardGate();

    ~ScavTrap();
};

#endif