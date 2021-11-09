#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta; delete i; delete j;

    std::cout << std::endl; 
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* cat2 = new WrongCat();
    std::cout << meta2->getType() << " " << std::endl;
    std::cout << cat2->getType() << " " << std::endl;
    meta2->makeSound();
    cat2->makeSound();
    delete meta2; delete cat2;

    system("leaks animal");
    return 0;
}