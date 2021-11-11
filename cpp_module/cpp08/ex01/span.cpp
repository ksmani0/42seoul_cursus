#include "span.hpp"

Span::Span(void) : mV(0), mN(0), mCurSize(0) {}
Span::Span(unsigned int n) : mV(n), mN(n), mCurSize(0) {}
Span::Span(const Span& ref) : mV(ref.mV), mN(ref.mN), mCurSize(ref.mCurSize) {}

Span& Span::operator=(const Span& ref)
{
    mV = ref.mV;
    mN = ref.mN;
    mCurSize = ref.mCurSize;
    return *this;
}

//////////

std::vector<int>& Span::GetOriginVector(void)
{
    return mV;
}

void Span::addNumber(int num)
{
    if (mN < mCurSize + 1)
        throw SpanException("This vector is already full!");
    mV.at(mCurSize) = num;
    ++mCurSize;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator iter;
    for (iter = begin; iter < end; ++iter)
    {
        if (mN < mCurSize + 1)
            throw SpanException("This vector is already full!");
        else
        {
            *iter = mCurSize;
            ++mCurSize;
        }
    }
}

int Span::shortestSpan(void)
{
    if (mCurSize <= 1)
        throw SpanException("This vector has 1 or less elements!");
    
    std::vector<int> temp;
    for (int i = 0; i < mCurSize; ++i)
        temp.push_back(mV.at(i));
    std::sort(temp.begin(), temp.end());

    std::vector<int>::iterator iter = temp.begin();
    int min1 = *iter;
    int min2 = *(++iter);

    if (min2 == min1)
        throw SpanException("This vector has only elements of the same value!");

    return min2 - min1;
}

int Span::longestSpan(void)
{
    if (mCurSize <= 1)
        throw SpanException("This vector has 1 or less elements!");
    
    std::vector<int> temp;
    for (int i = 0; i < mCurSize; ++i)
        temp.push_back(mV.at(i));
    std::sort(temp.begin(), temp.end());

    std::vector<int>::iterator iter = temp.begin();
    int min1 = *iter;
    int min2 = *(--temp.end());

    if (min2 == min1)
        throw SpanException("This vector has only elements of the same value!");

    return min2 - min1;
}

//////////

Span::SpanException::SpanException(std::string m) : mMessage(m) {}

const char* Span::SpanException::what(void) const throw()
{
    return mMessage.c_str();
}

Span::SpanException::~SpanException(void) throw () {}

/////////

Span::~Span(void) {}

/*
int Span::longestSpan(void)
{
    if (mCurSize <= 1)
        throw SpanException("This vector has 1 or less elements!");
    
    std::vector<int> temp(mV);
    std::sort(temp.begin(), temp.end());

    std::vector<int>::iterator iter = temp.begin();
    int min1 = *iter;
    int min2 = *(--temp.end());

    if (min2 == min1)
        throw SpanException("This vector has only elements of the same value!");

    return min2 - min1;
}
*/