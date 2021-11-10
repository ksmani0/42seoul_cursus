#include "Data.hpp"

int main(void)
{
    Data me = { "seungmki", 35, 164 };
    std::cout << "address of me: " << &me << std::endl;

    uintptr_t adr = serialize(&me);
    std::cout << "value of adr: " << adr << std::endl;

    Data* temp = deserialize(adr);
    std::cout << "value of temp: " << temp << std::endl;

    return 0;
}