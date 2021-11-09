#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& ref);

    std::string getType() const;
    void setType(std::string type);
    WrongAnimal& operator=(const WrongAnimal& ref);
    
    void makeSound() const;//일부러 virtual 지움
    ~WrongAnimal();

    protected:
    std::string type;
};

#endif