#include "Intern.hpp"

int main(void)
{
    Bureaucrat kim("kim", 3);
    Intern lee;//매개변수 없는 생성자 lee() 쓰면 함수 선언처럼 되니까 쓰면 안 됨

    Form* robotomy = lee.makeFome("robotomy request", "Bender");
    kim.signForm(*robotomy);
    kim.executeForm(*robotomy);

    std::cout << "\n\n";
    Form* shrubbery = lee.makeFome("shrubbery creation", "home");
    kim.signForm(*shrubbery);
    kim.executeForm(*shrubbery);

    std::cout << "\n\n";
    Form* president = lee.makeFome("presidential pardon", "corruption officials");
    kim.signForm(*president);
    kim.executeForm(*president);

    delete robotomy; delete shrubbery; delete president;

    std::cout << "\n\n";
    Form* nullPtr = lee.makeFome("x-form", "target");//존재하지 않는 Form 넣어서 예외 뜸
    if (nullPtr == NULL)//널 예외는 c++가 아닌 OS상 에러라서 try~catch 무소용
        std::cerr << "Null exception!\n";
    return 0;
}

/*
try
    {
        Form* nullPtr = lee.makeFome("x-form", "target");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Null exception!";
    }
*/