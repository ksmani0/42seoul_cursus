#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45), mTarget(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm ref)
{
    Form::operator=(ref);
    mTarget = ref.mTarget;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (GetSign() == false)
        throw ExecuteException("This form is unsigned!");
    if (GetExecuteGrade() < executor.GetGrade())
        throw GradeTooLowException("Bureaucrat's grade is low than execute grade!");
    
    srand((unsigned int)time(NULL));
    int evenOrOdd = rand() % 2;
    if (evenOrOdd != 0)
        std::cout << "Drrrrrrk! <" << mTarget << "> has been robotomized successfully!";
    else
        std::cout << "Drrrrrrk! <" << mTarget << "> robotization failed!";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}