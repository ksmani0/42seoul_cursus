#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap kim("kim");
	ClapTrap lee("lee");
	ClapTrap park("park");

	std::cout << std::endl;
	kim.attack("lee");
	lee.takeDamage(kim.GetHitPoint());
	std::cout << std::endl;

	lee.attack("kim");
	kim.takeDamage(lee.GetHitPoint());
	std::cout << std::endl;

	park.attack("lee");
	lee.takeDamage(park.GetHitPoint());
	std::cout << std::endl;
	
    lee.beRepaired(25);

	return (0);
}