#include "Cat.hpp"
#include "Dog.hpp"
//#include "WrongCat.hpp"

int main(void)
{
    Animal* j = new Dog();
    Animal* i = new Cat();

    Dog* dog = static_cast<Dog*>(j);
    Cat* cat = static_cast<Cat*>(i);
    cat->AddBrainIdea("Nyang Nyang!");
    dog->AddBrainIdea("Mung Mung!");
    std::cout << std::endl;
    
    Animal* pets[4];
    for (int k = 0; k < 2; ++k)
        pets[k] = new Dog(*dog);
    for (int k = 2; k < 4; ++k)
        pets[k] = new Cat(*cat);
    std::cout << std::endl;
    
    for (int k = 0; k < 4; ++k)
    {
        k < 2 ? std::cout << ((Dog*)pets[k])->GetBrainIdea(1) << std::endl :
        std::cout << ((Cat*)pets[k])->GetBrainIdea(1) << std::endl;
        delete pets[k];
    }
    std::cout << std::endl;

    delete j; delete i;
    system("leaks abstract"); 
    return 0;
}