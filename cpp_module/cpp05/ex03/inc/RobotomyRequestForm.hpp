#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{//sign 72, exec 45
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm& operator=(const RobotomyRequestForm ref);
    void execute(Bureaucrat const & executor) const;
    ~RobotomyRequestForm();
private:
    std::string mTarget;
};

#endif