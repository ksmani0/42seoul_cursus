#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
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

    class GradeTooHighException : public std::exception
    {
    public://exception에 정의된 가상함수 what(). override, noexcept은 c++11부터 사용
        const char* what() const throw();
    };//override 붙은 함수는 컴파일러가 기초 클래스에서 제공하는 가상함수인지 확인
    class GradeTooLowException : public std::exception
    {//throw()는 c++20부터 제거
    public:
        const char* what() const throw();
    };

    ~Form();

private:
    const std::string mName;
    bool mIsSigned;
    const int mSignGrade;
    const int mExecuteGrade;
};

std::ostream& operator<<(std::ostream&o, const Form& ref);

#endif