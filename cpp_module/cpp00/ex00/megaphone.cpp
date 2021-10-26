#include <iostream>
#include <cstring>

int main(int ac, char** av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }

    std::string result;
    for (int i = 1; i < ac; ++i)
        result += av[i];

    for (int i = 0; i < result.length(); ++i)
        result[i] = toupper(result[i]);
    std::cout << result << std::endl;

    return 0;
}