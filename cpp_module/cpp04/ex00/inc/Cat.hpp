#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat();
    Cat(const Cat& ref);

    Cat& operator=(const Cat& ref);
    void makeSound() const;//오버라이딩으로 재정의
    ~Cat();//virtaul 앞에 안 붙여도 기초 클래스에 붙어있으니 괜찮음
};

#endif