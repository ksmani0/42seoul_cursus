#include "ScalarConversion.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments!\n";
        return 0;
    }

    ScalarConversion conversion(av[1]);
    conversion.ToChar();
    conversion.ToInt();
    conversion.ToFloat();
    conversion.ToDouble();

    return 0;
}