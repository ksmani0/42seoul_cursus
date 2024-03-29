#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point	a(0, 0);
	Point	b(20, 0);
	Point	c(10, 30);
	Point	in(10, 15);
	Point	out(30, 50);

	std::cout << "Point \"in\" created at x:" << in.GetX() << " y:" << in.GetY() << std::endl;
	std::cout << "Point \"out\" created at x:" << out.GetX() << " y:" << out.GetY() << std::endl;
	if (bsp(a, b, c, in))
		std::cout << "\"in\" is in the triangle\n";
	else
		std::cout << "\"in\" is out of the triangle\n";
	if (bsp(a, b, c, out))
		std::cout << "\"out\" is in the triangle\n";
	else
		std::cout << "\"out\" is out of the triangle\n";
	return 0;
}