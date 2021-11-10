#include "Form.hpp"

Form::Form(void) : mName(""), mIsSigned(false),
mSignGrade(75), mExecuteGrade(100) {}

Form::Form(const Form& ref) : mName(ref.mName), mIsSigned(false),
mSignGrade(ref.mSignGrade), mExecuteGrade(ref.mExecuteGrade) {}

Form::Form(std::string name, int signGrade, int executionGrade)
: mName(name), mIsSigned(false), mSignGrade(signGrade), mExecuteGrade(executionGrade)
{
    if (mSignGrade < 1 || mExecuteGrade < 1)
        throw GradeTooHighException();
    else if (mSignGrade > 150 || mExecuteGrade > 150)
        throw GradeTooLowException();
}

//////////

Form& Form::operator=(const Form& ref)
{
    mIsSigned = ref.mIsSigned;
    return *this;
}
std::string Form::GetName(void) const
{
    return mName;
}
bool Form::GetSign(void) const
{
    return mIsSigned;
}
int Form::GetSignGrade(void) const
{
    return mSignGrade;
}
int Form::GetExecuteGrade(void) const
{
    return mExecuteGrade;
}
bool Form::beSigned(const Bureaucrat& check)
{
    if (check.GetGrade() <= mSignGrade)
    {
        mIsSigned = true;
        return true;
    }
    mIsSigned = false;
    return false;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Too high grade! the highest is grade 1";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Too low grade! the lowest is grade 150";
}

Form::~Form() {}

//////////

std::ostream& operator<<(std::ostream&o, const Form& f)
{
    o << "Form <" << f.GetName() << ">, a grade required to sign is <"
    << f.GetSignGrade() << "> and a grade required to execute is <"
    << f.GetExecuteGrade() << ">\n";
    return o;
}

/*
bool Form::beSigned(const Bureaucrat& check)
{
    if (check.GetGrade() >= mSignGrade)
    {
        std::cout << "bureaucrat <" << check.GetName() << "> signs form <" << GetName() << ">\n";
        mIsSigned = true;
        return true;
    }
    std::cout << "bureaucrat <" << check.GetName() << "> cannot signs form <"
    << mName << ">, because bureaucrat' s grade is lower than <" << mSignGrade << ">\n";
    mIsSigned = false;
    return false;
}
*/