#include "span.hpp"

int main(void)
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n*** exception test ***\n";
    Span sp1(4);
    sp1.addNumber(1);
    try
    {
        std::cout << sp1.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    sp1.addNumber(1);
    try
    {
        std::cout << sp1.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "\n*** 10000 numbers test in an ignorant way ***\n";
    Span sp2(10000);

    for (int i = 0; i < 10000; ++i)
        sp2.addNumber(i);//무식하게 함수 1만번 호출    
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    std::cout << "\n*** 10000 numbers test in a smart way ***\n";
    Span sp3(10000);

    try
    {
        std::vector<int>::iterator bIter = sp3.GetOriginVector().begin();
        std::vector<int>::iterator eIter = sp3.GetOriginVector().end();
        sp3.addNumber(bIter, eIter);//시작과 끝 반복자를 전달하는 함수 호출 1번만 했음

        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}