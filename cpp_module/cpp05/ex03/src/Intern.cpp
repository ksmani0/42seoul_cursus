#include "Intern.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern& ref) { (void)ref; }

Form* Intern::makeFome(std::string name, std::string target)
{
    std::string table[3] = {
        "shrubbery creation", "robotomy request", "presidential pardon" };

    std::string* ptr = std::find(table, table + 3, name);
    int idx = ptr - table;

    switch (idx)
    {
        case 0:
        std::cout << "Intern creates <ShrubberyCreationForm>\n";
        return new ShrubberyCreationForm(target);
        case 1:
        std::cout << "Intern creates <RobotomyRequestForm>\n";
        return new RobotomyRequestForm(target);
        case 2:
        std::cout << "Intern creates <PresidentialPardonForm>\n";
        return new PresidentialPardonForm(target);
        default:
        std::cout << "Wrong form was delivered! NULL will be returned!\n";
        return NULL;
    }
}

Intern& Intern::operator=(const Intern& ref)
{
    (void)ref;
    return *this;
}

Intern::~Intern() {}