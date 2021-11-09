#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Animal* j = new Dog();
    Animal* i = new Cat();

    Dog* dog = static_cast<Dog*>(j);
    Cat* cat = static_cast<Cat*>(i);
    cat->AddBrainIdea("Nyang Nyang!");
    dog->AddBrainIdea("Mung Mung!");
    std::cout << std::endl;
    
    Animal* pets[6];
    for (int k = 0; k < 3; ++k)
    {
        pets[k] = new Dog(*dog);
        //pets[k] = dog;//((Dog*)pets[k]) = dog;        
    }
    for (int k = 3; k < 6; ++k)
    {
        pets[k] = new Cat(*cat);//(Cat*)pets[k] = new Cat(*cat);
        //assignment to cast is illegal, lvalue casts are not supported
    }
    std::cout << std::endl;
    
    for (int k = 0; k < 6; ++k)
    {
        k < 3 ? std::cout << ((Dog*)pets[k])->GetBrainIdea(1) << std::endl :
        std::cout << ((Cat*)pets[k])->GetBrainIdea(1) << std::endl;
        delete pets[k];
    }
    std::cout << std::endl;

    delete j; delete i;    
    return 0;
}