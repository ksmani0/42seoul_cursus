#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{//형 변환 연산자인 reinterpret<T>()은 포인터 관련 모든 자료형 변환에 쓰임
    return reinterpret_cast<uintptr_t>(ptr);
}//이렇게 주소값을 정수로 변환하거나
Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}//정수를 주소값으로 변환 가능