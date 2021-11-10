#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : mName("default"), mGrade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat& ref)
: mName(ref.mName), mGrade(ref.mGrade) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
: mName(name)
{
    if (grade < 1)
        throw GradeTooHighException("Too high grade!");
    else if (grade > 150)
        throw GradeTooLowException("Too low grade!");
    mGrade = grade;
}

//////////

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
    mGrade = ref.mGrade;
    return *this;
}

std::string Bureaucrat::GetName(void) const
{
    return mName;
}
int Bureaucrat::GetGrade(void) const
{
    return mGrade;
}

void Bureaucrat::UpGrade(int n)
{
    if (mGrade - n <= 0)
        throw GradeTooHighException("Too high grade!");
    mGrade -= n;
}
void Bureaucrat::DownGrade(int n)
{
    if (mGrade + n >= 151)
        throw GradeTooLowException("Too low grade!");
    mGrade += n;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        if (form.beSigned(*this) == true)
            std::cout << "bureaucrat <" << mName << "> signs form <" << form.GetName() << ">\n";
        else
            throw GradeTooLowException("Bureaucrat cannot signs this form!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n<" << mName << ">'s grade is lower than form <"
        << form.GetName() << ">'s grade <" << form.GetSignGrade() << "> for sign.\n";
    }
}

void Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

Bureaucrat::~Bureaucrat(void) {}

//////////

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string m)
: mMessage(m) {}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return mMessage.c_str();
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string m)
: mMessage(m) {}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return mMessage.c_str();
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

//////////

std::ostream& operator<<(std::ostream& o, const Bureaucrat& ref)
{
    o << "bureaucrat <" << ref.GetName() << ">, grade <"
    << ref.GetGrade() << ">\n";
    return o;
}