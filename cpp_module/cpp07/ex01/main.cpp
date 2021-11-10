#include "iter.hpp"

int main(void)
{
    std::string str[3] = { "cat", "game", "sleep" };
    iter(str, 3, PrintArr);

    std::cout << "\n";
    int intArr[5] = { 2800, 74, 10, -17, 99 };
    iter(intArr, sizeof(intArr) / sizeof(int), AddFiveNPrint);
    //템플릿 함수는 iter<T> 형태로 안 써도 됨. 컴파일러가 인자 자료형을 추측해서 대입해줌

    std::cout << "\n";
    double doubleArr[4] = { -42.1, -1.5, 0.0, 109.8 };
    iter(doubleArr, sizeof(doubleArr) / sizeof(double), AddFiveNPrint);

    return 0;
}