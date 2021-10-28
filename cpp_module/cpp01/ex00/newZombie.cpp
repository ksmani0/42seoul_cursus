#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* ptr = new Zombie(name);
    return ptr;
}