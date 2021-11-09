#include "Cat.hpp"

Cat::Cat(void)
{//Animal() 자동 호출
    setType("Cat");
    brain = new Brain();
    std::cout << "Cat default Constructor called\n";
}
Cat::Cat(const Cat& ref) : Animal(ref)
{
    brain = new Brain(*(ref.brain));
    std::cout << "Cat Copy Constructor called\n";
}

Cat& Cat::operator=(const Cat& ref)
{//내 대입연산자는 기초클래스 대입연산자를 자동 호출 안 하니 직접 호출
    Animal::operator=(ref);
    brain = ref.brain;
    return *this;
}
void Cat::makeSound(void) const
{
    std::cout << type << " howled. Myaaaong!\n";
}
std::string Cat::GetBrainIdea(unsigned int idx) const
{
    if (idx > 0)
        --idx;
    return brain->GetIdea(idx);
}
bool Cat::AddBrainIdea(std::string idea)
{
    return brain->AddIdea(idea);
}

Cat::~Cat(void)
{
    delete brain;
    std::cout << "Cat Destructor called\n";
}