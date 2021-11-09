#include "Dog.hpp"

Dog::Dog(void)
{//Animal() 자동 호출
    setType("Dog");
    brain = new Brain();
    std::cout << "Dog default Constructor called\n";
}
Dog::Dog(const Dog& ref) : Animal(ref)
{
    brain = new Brain(*(ref.brain));
    std::cout << "Dog Copy Constructor called\n";
}

Dog& Dog::operator=(const Dog& ref)
{//내 대입연산자는 기초클래스 대입연산자를 자동 호출 안 하니 직접 호출
    Animal::operator=(ref);
    brain = ref.brain;
    return *this;
}
void Dog::makeSound(void) const
{
    std::cout << type << " howled. MeongMeong!\n";
}
std::string Dog::GetBrainIdea(unsigned int idx) const
{
    if (idx > 0)
        --idx;
    return brain->GetIdea(idx);
}
bool Dog::AddBrainIdea(std::string idea)
{
    return brain->AddIdea(idea);
}

Dog::~Dog(void)
{
    delete brain;
    std::cout << "Dog Destructor called\n";
}