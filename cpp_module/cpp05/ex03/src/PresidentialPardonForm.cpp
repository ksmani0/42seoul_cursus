#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", 25, 5), mTarget(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm ref)
{
    Form::operator=(ref);
    mTarget = ref.mTarget;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (GetSign() == false)
        throw ExecuteException("This form is unsigned!");
    if (GetExecuteGrade() < executor.GetGrade())
        throw GradeTooLowException("Bureaucrat's grade is low than execute grade!");
    
    std::cout << "<" << mTarget << "> has been pardoned by Zafod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}