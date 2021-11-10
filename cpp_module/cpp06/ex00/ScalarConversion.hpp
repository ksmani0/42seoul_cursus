#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <exception>

class ScalarConversion
{
public:
    ScalarConversion();
    ScalarConversion(std::string value);
    ScalarConversion(const ScalarConversion& ref);

    ScalarConversion& operator=(const ScalarConversion& ref);
    void ToChar() const;
    void ToInt() const;
    void ToFloat() const;
    void ToDouble() const;

    class ConversionException : public std::exception
    {
    public:
        ConversionException(std::string m);
        const char* what() const throw();
        ~ConversionException() throw();
    private:
        std::string mMessage;
    };

    ~ScalarConversion();

private:
    std::string mValue;
    double mDouble;
    bool mNan;
    bool mInf;
};

#endif

/*
    char mChar;
    int mInt;
    float mFloat;
*/