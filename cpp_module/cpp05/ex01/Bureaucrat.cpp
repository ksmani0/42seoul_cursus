#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : mName(""), mGrade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat& ref)
: mName(ref.mName), mGrade(ref.mGrade) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
: mName(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    mGrade = grade;
}

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
        throw GradeTooHighException();
    mGrade -= n;
}
void Bureaucrat::DownGrade(int n)
{
    if (mGrade + n >= 151)
        throw GradeTooLowException();
    mGrade += n;
}

void Bureaucrat::signForm(Form form)
{
    try
    {
        if (form.beSigned(*this) == true)
            std::cout << "bureaucrat <" << mName << "> signs form <" << form.GetName() << ">\n";
        else
            throw GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "bureaucrat <" << mName << "> cannot signs form <"
        << form.GetName() << ">, because bureaucrat's grade is lower than <"
        << form.GetSignGrade() << ">\n";
    }
}

Bureaucrat::~Bureaucrat(void) {}

//////////

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Too high grade!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Too low grade!";
}

//////////

std::ostream& operator<<(std::ostream& o, const Bureaucrat& ref)
{
    o << "<" << ref.GetName() << ">, bureaucrat grade <"
    << ref.GetGrade() << ">\n";
    return o;
}