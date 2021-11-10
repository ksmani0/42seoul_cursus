#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    srand((unsigned int)time(NULL));

    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;

    return 0;
}