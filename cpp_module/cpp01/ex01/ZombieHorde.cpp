#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* ptr = new Zombie[N];
    std::stringstream s;

    for (int i = 0; i < N; ++i)
    {
        s << i;
        ptr[i].SetmName(name + s.str());
        s.str(std::string());
    }//to_string(), itoa()은 c++11
    return ptr;
}