#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{//sign 25, exec 5
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm& operator=(const PresidentialPardonForm ref);
    void execute(Bureaucrat const & executor) const;
    ~PresidentialPardonForm();
private:
    std::string mTarget;
};

#endif