#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat kim("kim", 15);
    std::cout << kim;

    ShrubberyCreationForm a("home");
    kim.signForm(a);
    kim.executeForm(a);//처음에는 다 됨

    std::cout << std::endl;
    kim.DownGrade(130);//145
    std::cout << kim;
    kim.executeForm(a);//실행만 안 됨

    std::cout << std::endl;
    RobotomyRequestForm b("judges");
    kim.signForm(b);//사인도 안 됨

    std::cout << std::endl;
    kim.UpGrade(130);//15
    std::cout << kim;
    kim.signForm(b);//이젠 다 됨
    kim.executeForm(b);

    std::cout << "\n\n";
    PresidentialPardonForm c("corruption officials");
    kim.signForm(c);
    kim.executeForm(c);//사인은 되는데 실행 안 됨

    std::cout << std::endl;
    try
    {
        kim.UpGrade(15);//예외 발생으로 15
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    

    std::cout << kim;
    kim.UpGrade(10);//5
    std::cout << kim;
    kim.executeForm(c);//실행 됨

    return 0;
}