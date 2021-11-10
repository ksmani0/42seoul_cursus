#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& ref);
    Form* makeFome(std::string name, std::string target);
    Intern& operator=(const Intern& ref);
    ~Intern();
};

#endif