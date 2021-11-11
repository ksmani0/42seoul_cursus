#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
public:
    Span(unsigned int n);
    Span(const Span& ref);
    Span& operator=(const Span& ref);

    std::vector<int>& GetOriginVector();
    void addNumber(int num);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();

    class SpanException : public std::exception
    {
    public:
        SpanException(std::string m);
        const char* what() const throw();
        ~SpanException() throw();
    private:
        std::string mMessage;
    };
    ~Span();

private:
    std::vector<int> mV;
    unsigned int mN;//vector의 size() 역할
    unsigned int mCurSize;

    Span();
};

#endif