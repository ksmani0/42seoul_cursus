#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
    //클래스 정의 안에 예외 클래스 선언을 내포시켜 예외들을 클래스 안에 병합시킬 수 있다

    ~Bureaucrat();

private:
	const std::string mName;
	int mGrade;//1~150
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& ref);

#endif