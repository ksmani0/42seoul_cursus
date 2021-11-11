#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}//MutantStack<T>::stack()는 자동 호출
    MutantStack(const MutantStack<T>& ref) : MutantStack<T>::stack(ref) {}
    //stack<T> 쓰면 use 'template' keyword to treat 'stack' as a dependent template name 오류
    
    MutantStack<T>& operator=(const MutantStack<T>& ref)
    {
        MutantStack<T>::stack::operator=(ref);//마찬가지로 stack<T>에서 수정
        return *this;
    }

    //container_type는 스택의 기초 클래스인 deque. deque의 반복자 반환 함수를 호출하도록 함수 만들기
    //초반엔 container_type 대신 c 썼다가 오류. 이건 멤버 변수(deque 객체) 이름이니 사용하면 안 됐음
    //'c' is not a class, namespace, or enumeration
    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;

    iterator begin(void)
    {
        return this->c.begin();
    }
    iterator end(void)
    {
        return this->c.end();
    }

    const_iterator begin(void) const
    {
        return this->c.begin();
    }
    const_iterator end(void) const
    {
        return this->c.end();
    }

    ~MutantStack() {}
};

#endif

/*
    // iterators:

    _LIBCPP_INLINE_VISIBILITY
    iterator       begin() _NOEXCEPT       {return __base::begin();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator begin() const _NOEXCEPT {return __base::begin();}
    _LIBCPP_INLINE_VISIBILITY
    iterator       end() _NOEXCEPT         {return __base::end();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator end()   const _NOEXCEPT {return __base::end();}
*/