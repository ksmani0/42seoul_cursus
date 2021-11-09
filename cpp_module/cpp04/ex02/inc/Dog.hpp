#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
    Dog();
    Dog(const Dog& ref);

    Dog& operator=(const Dog& ref);
    void makeSound() const;//오버라이딩으로 재정의
    std::string GetBrainIdea(unsigned int idx) const;
    bool AddBrainIdea(std::string idea);
    ~Dog();//virtaul 앞에 안 붙여도 기초 클래스에 붙어있으니 괜찮음

    private:
    Brain* brain;
};

#endif