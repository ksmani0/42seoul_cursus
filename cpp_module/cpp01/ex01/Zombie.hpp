#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>

class Zombie
{
    public:
    Zombie(void);
    Zombie(std::string s);
    void SetmName(std::string s);
    void announce(void);    
    ~Zombie(void);

    private:
    std::string mName;
};

Zombie* zombieHorde(int N, std::string name);

#endif