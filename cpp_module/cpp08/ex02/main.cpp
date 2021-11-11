#include "mutantstack.hpp"

int main(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack.top(): " << mstack.top() << std::endl;//17

    mstack.pop();
    std::cout << "mstack.size(): " << mstack.size() << std::endl;//1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737); //5 3 5 737

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;//5 3 5 737
        ++it;
    }
    std::cout << "--ite value: " << *(--ite) << std::endl;//737

    std::cout << "\n*** const iterator test ***\n";

    const MutantStack<int> constMS(mstack);
    MutantStack<int>::const_iterator cIt = constMS.begin();
    MutantStack<int>::const_iterator cIte = constMS.end();

    while (cIt != cIte)
    {
        std::cout << *cIt << std::endl;//5 3 5 737
        ++cIt;
    }
    std::cout << "--cIte value: " << *(--cIte) << std::endl;//737

    return 0;
}