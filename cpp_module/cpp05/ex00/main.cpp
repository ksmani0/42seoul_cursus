#include "Bureaucrat.hpp"

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

        Bureaucrat lee("lee", 0);//에러 나야 함
        std::cout << lee;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat park("park", 100);
        std::cout << park;

        park.DownGrade(51);//에러 나야 함
        std::cout << park;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}