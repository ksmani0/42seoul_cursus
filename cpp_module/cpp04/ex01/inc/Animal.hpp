#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
    Animal();
    Animal(const Animal& ref);

    std::string getType() const;
    void setType(std::string type);
    Animal& operator=(const Animal& ref);
    
    virtual void makeSound() const;
    virtual ~Animal();

    protected:
    std::string type;
};

#endif