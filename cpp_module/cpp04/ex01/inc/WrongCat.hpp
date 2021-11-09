#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(const WrongCat& ref);

    WrongCat& operator=(const WrongCat& ref);
    void makeSound() const;//오버라이딩으로 재정의
    ~WrongCat();//virtaul 앞에 안 붙여도 기초 클래스에 붙어있으니 괜찮음
};

#endif