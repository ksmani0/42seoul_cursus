#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& ref);

    FragTrap& operator=(FragTrap const& src);
    void highFivesGuys(void);

    ~FragTrap();
};

#endif