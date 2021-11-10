#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
    int idx = rand() % 3;

    switch (idx)
    {
        case 0:
        return new A;
        case 1:
        return new B;
        default:
        return new C;
    }
}

void identify(Base* p)
{//기초 클래스가 가상함수를 1개라도 가졌으면 폴리모픽 클래스가 됨.
    A* a = dynamic_cast<A*>(p);//이 연산자로 기초 클래스 포인터, 참조자를
    if (a != NULL)//유도 클래스 포인터, 참조자로 변환 가능
    {
        std::cout << "I'm A\n";
        return;
    }
    
    B* b = dynamic_cast<B*>(p);
    if (b != NULL)
    {
        std::cout << "I'm B\n";
        return;
    }

    C* c = dynamic_cast<C*>(p);
    if (c != NULL)
    {
        std::cout << "I'm C\n";
        return;
    }
}

void identify(Base& p)
{
    A a; B b; C c;

    try
    {//포인터로 반환했을 때 예외가 발생하면 NULL이 대입되지만
        a = dynamic_cast<A&>(p);//참조자는 bad_cast 예외 발생
        std::cout << "I'm A\n";
        return;
    }
    catch(std::bad_cast expt) {}
    
    try
    {
        b = dynamic_cast<B&>(p);
        std::cout << "I'm B\n";
        return;
    }
    catch(std::bad_cast expt) {}

    try
    {
        c = dynamic_cast<C&>(p);
        std::cout << "I'm C\n";
        return;
    }
    catch(std::bad_cast expt) {}
}