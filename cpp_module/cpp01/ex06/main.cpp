#include "Karen.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cout << "Invalid number of arguments!\n";
        return 0;
    }

    Karen karen;
    karen.complain(av[1]);

    return 0;
}
