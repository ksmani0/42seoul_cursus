#include "Array.hpp"

int main(void)
{
    Array<int> arr1(4);
    arr1[0] = -3; arr1[1] = -89; arr1[2] = 10; arr1[3] = 756;

    for (int i = 0; i < arr1.size(); ++i)
        std::cout << "[" << i << "]: " << arr1[i] << "\n";
    
    try
    {
        arr1[4] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n";
    Array<std::string> arr2;
    std::cout << "arr2.size(): " << arr2.size() << "\n";

    Array<std::string> arr3(2);
    arr3[0] = "happy"; arr3[1] = "days";

    arr2 = arr3;
    for (int i = 0; i < arr2.size(); ++i)
        std::cout << "[" << i << "]: " << arr2[i] << "\n";
    
    try
    {
        arr3[-1] = ":)";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    system("leaks Array");

    return 0;
}