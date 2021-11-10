#include "Form.hpp"

Form::Form(void) : mName("default"), mIsSigned(false),
mSignGrade(75), mExecuteGrade(100) {}

Form::Form(const Form& ref) : mName(ref.mName), mIsSigned(false),
mSignGrade(ref.mSignGrade), mExecuteGrade(ref.mExecuteGrade) {}

Form::Form(std::string name, int signGrade, int executionGrade)
: mName(name), mIsSigned(false), mSignGrade(signGrade), mExecuteGrade(executionGrade)
{
    if (mSignGrade < 1 || mExecuteGrade < 1)
        throw GradeTooHighException("Too high grade! the highest is grade 1");
    else if (mSignGrade > 150 || mExecuteGrade > 150)
        throw GradeTooLowException("Too low grade! the lowest is grade 150");
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

//////////

Form::GradeTooHighException::GradeTooHighException(std::string m) : mMessage(m) {}
const char* Form::GradeTooHighException::what() const throw()
{
    return mMessage.c_str();
}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException(std::string m) : mMessage(m) {}
const char* Form::GradeTooLowException::what() const throw()
{
    return mMessage.c_str();
}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::ExecuteException::ExecuteException(std::string m) : mMessage(m) {}
const char* Form::ExecuteException::what() const throw()
{
    return mMessage.c_str();
}
Form::ExecuteException::~ExecuteException() throw() {}

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