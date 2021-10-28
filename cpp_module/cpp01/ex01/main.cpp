#include "Zombie.hpp"

int main(void)
{
    int num = 5;
    Zombie* arr = zombieHorde(num, "zombies");

    for (int i = 0; i < num; ++i)
    {
        arr[i].announce();
    }
    delete[] arr;

    return 0;
}