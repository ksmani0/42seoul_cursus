#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 145, 137), mTarget(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
    Form::operator=(ref);
    mTarget = ref.mTarget;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{//beSigned()는 const 함수가 아니라서 호출 불가
    if (GetSign() == false)
        throw ExecuteException("This form is unsigned!");
    if (GetExecuteGrade() < executor.GetGrade())
        throw GradeTooLowException("Bureaucrat's grade is low than execute grade!");
    
    std::string path(mTarget);
    path.append("_shrubbery");

    std::fstream output;
    output.open(path, std::ios::out);
    if (output.fail())
        throw ExecuteException("Error occurred during file opening!");
    output << SHRUBBERY;
    output.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
