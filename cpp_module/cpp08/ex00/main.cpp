#include <vector>
#include <iterator>
#include "easyfind.hpp"

int main(void)
{
    int nums[8]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
    std::vector<int> v1(nums, nums + sizeof(nums) / sizeof(int));
    //cpp01 ex02 tests.cpp, 모두의코드 확인했지만 문제 없음

    std::vector<int>::iterator iter = easyfind(v1, 42);
    std::cout << *iter << std::endl;;

    try
    {
        iter = easyfind(v1, -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
