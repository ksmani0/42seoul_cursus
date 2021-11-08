#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap kim("kim");
	ScavTrap lee("lee");
	std::cout << std::endl;

	kim.attack("lee");
	lee.takeDamage(kim.GetAttackDamage());
	std::cout << std::endl;

	lee.attack("kim");
	kim.takeDamage(lee.GetAttackDamage());
	std::cout << std::endl;

	kim.guardGate();
	lee.guardGate();

	return (0);
}