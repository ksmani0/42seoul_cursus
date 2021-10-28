#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string s) : mName(s) {}

void Zombie::SetmName(std::string s)
{
    mName = s;
}

void Zombie::announce(void)
{
    std::cout << "<" << mName << "> BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(void)
{
    std::cout << "<" << mName << "> destructor called!\n";
}