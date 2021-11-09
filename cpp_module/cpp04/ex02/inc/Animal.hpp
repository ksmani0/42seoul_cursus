#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{//순수가상함수 있어서 추상클래스 됐음
    public:
    Animal();
    Animal(const Animal& ref);

    std::string getType() const;
    void setType(std::string type);
    Animal& operator=(const Animal& ref);
    
    virtual void makeSound() const = 0;//순수가상함수
    virtual ~Animal();

    protected:
    std::string type;
};

#endif