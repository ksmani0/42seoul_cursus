#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen
{
    public:
    Karen(void);
    void complain(std::string level);

    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void (Karen::*f[4])(void);//Karen 클래스에 있는 함수 주소 받는 형태
    //void (*f[4])(void); 어떤 함수 주소든 받는 형태
    //이걸로 하면 Karen의 멤버함수 주소 못 받음
};

#endif