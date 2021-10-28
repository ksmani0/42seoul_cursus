#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>

class Zombie
{
    public:
    Zombie(std::string s);
    void announce(void);
    ~Zombie(void);

    private:
    std::string mName;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif