#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& ref);
    Bureaucrat(std::string name, int grade);

    Bureaucrat& operator=(const Bureaucrat& ref);
    std::string GetName() const;
	int GetGrade() const;
	void UpGrade(int n);
	void DownGrade(int n);
    void signForm(Form& form);//Form이 추상클래스가 되면서
    //함수 매개변수로 복사해올 때 임시 객체를 복사해올 수 없어짐. 포인터나 참조자로만
    //외부의 Form 파생 클래스 객체를 받아올 수 있음
    void executeForm(Form const & form);
    
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
    //클래스 정의 안에 예외 클래스 선언을 내포시켜 예외들을 클래스 안에 병합시킬 수 있다

    ~Bureaucrat();

private:
	const std::string mName;
	int mGrade;//1~150
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& ref);

#endif