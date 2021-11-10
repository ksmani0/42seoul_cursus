#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form();
    Form(const Form& ref);
    Form(std::string name, int signGrade, int executeGrade);

    Form& operator=(const Form& ref);
    std::string GetName() const;
    bool GetSign() const;
    int GetSignGrade() const;
    int GetExecuteGrade() const;
    bool beSigned(const Bureaucrat& check);
    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public://exception에 정의된 가상함수 what(). override, noexcept은 c++11부터 사용
        GradeTooHighException(std::string m);
        const char* what() const throw();
        ~GradeTooHighException() throw();
    private:
        std::string mMessage;
    };//override 붙은 함수는 컴파일러가 기초 클래스에서 제공하는 가상함수인지 확인
    class GradeTooLowException : public std::exception
    {//throw()는 c++20부터 제거
    public:
        GradeTooLowException(std::string m);
        const char* what() const throw();
        ~GradeTooLowException() throw();
    private:
        std::string mMessage;
    };
    class ExecuteException : public std::exception
    {
    public:
        ExecuteException(std::string m);
        const char* what() const throw();
        ~ExecuteException() throw();
    private:
        std::string mMessage;
    };

    virtual ~Form();

private:
    const std::string mName;
    bool mIsSigned;
    const int mSignGrade;
    const int mExecuteGrade;
};

std::ostream& operator<<(std::ostream&o, const Form& ref);

#endif