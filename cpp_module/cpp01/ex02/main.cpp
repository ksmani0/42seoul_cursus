#include <iostream>
#include <cstring>

int main(void)
{
    std::string s("HI THIS IS BRAIN");
    std::string* stringPtr = &s;
    std::string& stringRef = s;

    std::cout << "address of s : " << &s << std::endl;
    std::cout << "value of stringPtr : " << stringPtr << std::endl;
    std::cout << "address of stringRef : " << &stringRef << std::endl;
	std::cout << "stringPtr's string : " << *stringPtr << std::endl;
	std::cout << "stringRef's string : " << stringRef << std::endl;

    return 0;
}
