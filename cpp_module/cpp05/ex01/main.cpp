#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat kim("kim", 15);
        std::cout << kim;

        kim.UpGrade(7);//8
        std::cout << kim;
        kim.DownGrade(90);//98
        std::cout << kim;

        Form("a", 1, 0);//예외 나야 함
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    Bureaucrat park("park", 10);
    std::cout << park;

    park.DownGrade(51);//61
    std::cout << park;

    park.signForm(Form("b", 70, 70));
    park.signForm(Form("c", 30, 30));//예외 나야 함
    
    return 0;
}